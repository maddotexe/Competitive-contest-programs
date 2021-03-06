#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        if( argc != 2 ){ 
		    printf("help:u need to put server ip\n"); 
		    exit(0);
        }
        
        int fd,temp,k,len;
        struct sockaddr_in servaddr;
        char buf[1000];
 	    fd_set rdfs;       
        fd = socket(AF_INET,SOCK_STREAM,0);
        memset(&servaddr, 0, sizeof(servaddr));

        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(8888);
        servaddr.sin_addr.s_addr = inet_addr(argv[1]);

        temp = connect(fd,(struct sockaddr *)&servaddr,sizeof(servaddr));

        if(temp == 0)
                printf("Connection successfull\n");
	
	while (1) {
                FD_ZERO(&rdfs);
                FD_SET(0,&rdfs);
                FD_SET(fd,&rdfs);
                select(fd+1,&rdfs,NULL,NULL,NULL);
                if(FD_ISSET(fd,&rdfs)) {
                        k=recv(fd,buf,sizeof(buf),0);                                               
                        puts(buf);
                }
                if(FD_ISSET(0,&rdfs)) {
                        gets(buf);
                        k=send(fd,buf,sizeof(buf),0);
                }

        }

        close(fd);
        return 0;
}
                                 