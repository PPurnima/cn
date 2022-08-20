#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
    
#define PORT     8090  
#define MAXLINE 1024 
   
int main() { 
    int sfd;  
    int bfd; 
   char buffer[MAXLINE];      
    struct sockaddr_in sadd; 
    sfd = socket(AF_INET, SOCK_DGRAM, 0); 
    if ( sfd==-1 ) 
    { 
        printf("Socket not created:");
        exit(0); 
    }
   
    sadd.sin_family    = AF_INET;
    sadd.sin_addr.s_addr = INADDR_ANY; 
    sadd.sin_port = htons(PORT); 
    printf("Socket created sucessfully\n");
    int arr[2],result;
    printf("Enter two numbers:");
    scanf("%d%d",&arr[0],&arr[1]);
    int n, len; 
    sendto(sfd, &arr,2*sizeof(int),MSG_CONFIRM, (const struct sockaddr *) &sadd,sizeof(sadd)); 
    printf("message sent.\n");
    n = recvfrom(sfd, &result, MAXLINE,MSG_WAITALL, (struct sockaddr *) &sadd,&len); 
    printf("Server : %d\n", result); 
    close(sfd);   
    return 0; 
}
