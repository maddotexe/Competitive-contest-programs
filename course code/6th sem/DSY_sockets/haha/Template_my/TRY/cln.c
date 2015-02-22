#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 


int sockfd = 0, n = 0, i;
char recvBuff[1024], sendBuff[1024];
int send_len = 1024;

struct sockaddr_in serv_addr; 
char *addr;
char *str = "agrawal";
void setUp(){
	memset(recvBuff, '0',sizeof(recvBuff));
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
	        printf("\n Error : Could not create socket \n");
	}
    	memset(&serv_addr, '0', sizeof(serv_addr)); 
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5000); 

	if(inet_pton(AF_INET, addr, &serv_addr.sin_addr) <= 0){
	        printf("\n inet_pton error occured\n");
    	} 

}

int main(int ar, char *arv[])
{

        if(ar != 2) {
                printf("\n Usae: %s <ip of server> \n", arv[0]);
                addr = "127.0.0.1";
        } else {
	        addr = arv[1];
        }
	
	setUp();
        if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        	printf("\n Error : Connect Failed \n");
	        return 1;
        } 
	// read from server
	while (recvBuff[0] != '-') {
        	while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
        	{
                	recvBuff[n] = 0;
	                if(fputs(recvBuff, stdout) == EOF) {
        	                printf("\n Error : Fputs error\n");
	                } else {
				 break;
			}
       	 	} 

	        printf("read Complete\n");
	}
	
        return 0;
}
