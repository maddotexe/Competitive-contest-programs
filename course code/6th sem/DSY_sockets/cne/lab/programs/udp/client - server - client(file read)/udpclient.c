#include <sys/socket.h>  
#include <netinet/in.h>  
#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>  
#include <arpa/inet.h>  
#include <unistd.h> 

int main()
{
    struct sockaddr_in client, server;
    char a[100];
    int fd, addr_len, len, i;

    memset(&server, 0, sizeof(server));
    memset(&client, 0, sizeof(client));
    
    server.sin_family = AF_INET;
    server.sin_port = htons(7780);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd < 0)
    {
          printf("socket error !!");
    }
    
     while(1)
     {  
	for (i = 0; i < 100; i++) {
		a[i] = '\0';
	}
	gets(a);
     	len = sendto(fd, a, 100, 0, (struct sockaddr*)&server, sizeof(server));
	addr_len = sizeof(server);
	len = recvfrom(fd, a, 100, 0, (struct sockaddr*)&server, &addr_len);
	puts(a);
     }
         
    return 0;
}      
