#include <sys/socket.h>  
#include <netinet/in.h>  
#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>  
#include <arpa/inet.h>  
#include <unistd.h> 

int main()
{
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd == -1)
    {
          printf("cannot create socket !!\n");
          return 0;
    }
    
    struct sockaddr_in server, client;
    bzero(&server, sizeof(server));
    bzero(&client, sizeof(client));
    
    server.sin_family = AF_INET;
    server.sin_port = htons(7780);
    server.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(fd, (struct sockaddr*)&server, sizeof(server)) != 0)
    {
                printf("cannot bind socket !!\n");
                close(fd);
                return 0;
    }
    
    int addr_len, len;
    char msg[100];
    
    while(1)
    {   
       addr_len = sizeof(client);
       len = recvfrom(fd, msg, 100, 0, (struct sockaddr*)&client, &addr_len);       
       printf("%s\n", msg);
    //   addr_len = sizeof(client);
        len = sendto(fd, "hello client", 12, 0, (struct sockaddr*)&client, sizeof(client));

    }
    close (fd);
    return 0;
    
}
            
