#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "netdb.h"
#include "arpa/inet.h"
#define h_addr h_addr_list[0] 
#define PORT 9029
#define MAX 1000  

int main(){
    char serverResponse[MAX];
    char clientResponse[MAX];
    int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    char hostname[MAX], ipaddress[MAX];
    struct hostent *hostIP; 

if(gethostname(hostname,sizeof(hostname))==0){
    hostIP = gethostbyname(hostname);
}

struct sockaddr_in serverAddress;
serverAddress.sin_family = AF_INET;
serverAddress.sin_port = htons(PORT);
serverAddress.sin_addr.s_addr = INADDR_ANY; 

connect(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    while (1)
    {   
        recv(socketDescriptor, serverResponse, sizeof(serverResponse), 0);
          
            printf("\nSERVER MESSAGE : %s", serverResponse);
        
    printf("\nYOUR MESSAGE :");
    scanf("%s", clientResponse);
    send(socketDescriptor, clientResponse, sizeof(clientResponse), 0);
    }


    close(socketDescriptor);
    return 0;
}
