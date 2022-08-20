#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#define MAXLINE 1024 
#define PORT     8090  
   
int main() { 
    int sfd;  
    int bfd; 
    struct sockaddr_in sadd,cadd; 
    char buffer[MAXLINE]; 
    
    sfd = socket(AF_INET, SOCK_DGRAM, 0); 
    if ( sfd==-1 ) 
    { 
        printf("Socket not created:");
        exit(0); 
    }
    else{ 
    	sadd.sin_family    = AF_INET;
    	sadd.sin_addr.s_addr = INADDR_ANY; 
    	sadd.sin_port = htons(PORT); 
    	printf("Socket created sucessfully\n");
    	bfd=bind(sfd, (const struct sockaddr *)&sadd,sizeof(sadd));
    	if ( bfd==-1 ) 
    	{ 
        	printf("Binding not sucessfull:");
        	exit(0);
    	}   
    else
    	printf("Binding Sucessfull!\n"); 
    	int len, n; 
    
    	len = sizeof(cadd);  //len is value/result 
    	int arr[2],result;
    	n = recvfrom(sfd, &arr, MAXLINE,MSG_WAITALL, ( struct sockaddr *) &cadd,&len); 
    	printf("Client : %d %d\n",arr[0],arr[1]); 
    	result=arr[0]+arr[1];
    	sendto(sfd, &result, sizeof(int),MSG_CONFIRM, (const struct sockaddr *) &cadd,len); 
    	printf("message sent.\n"); 
        printf("    ------     \n");
        }
    
    return 0; 
}
