#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
    
#define PORT     8080  
   int bfd; 
int main() { 
    int sfd;  
    struct sockaddr_in sadd; 
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
       printf("Binding not sucessful:");
        exit(0);
    } 
        
    else
    	printf("Binding Sucessfull!\n"); 
        }
 
    
        
    
        
    return 0; 
}
