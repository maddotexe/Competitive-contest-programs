#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 


int listenfd = 0, connfd = 0, n, i;
struct sockaddr_in serv_addr; 

char sendBuff[1025], recvBuff[1025];
time_t ticks; 
void setUp()
{
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
    	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff)); 
        serv_addr.sin_family = AF_INET;
    	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    	serv_addr.sin_port = htons(5000); 
    
   	 /* bind the socket to the port and ip address */
    	bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 
}

int main(int argc, char *argv[])
{
	int n = 5, i;
	int a[] = {1, 2, 3, 4, 5};
	setUp();
    	listen(listenfd, 10); 
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
//    	while(1)
  //  	{
	for (i = 0; i < n; i++) {
 		//connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
	
	        scanf("%s", sendBuff);
	        write(connfd, sendBuff, strlen(sendBuff)); 
	     	printf("written \n");
	}
	close(connfd);
}
