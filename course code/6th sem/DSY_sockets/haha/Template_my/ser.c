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
	setUp();
    	listen(listenfd, 10); 
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
//    	while(1)
  //  	{

 		//connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
	
	       	memset(recvBuff, '0', sizeof(recvBuff));
	        ticks = time(NULL);
	        snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
	        write(connfd, sendBuff, strlen(sendBuff)); 
	     	printf("written \n");
		n = read(connfd, recvBuff, sizeof(recvBuff) - 1);
		recvBuff[n] = '\0';
		printf("read %d\n", n);
		for (i = 0; i < n; i++) printf("%c",recvBuff[i]);
		printf("\n");
		//printf("%s\n", recvBuff);
		//fputs(recvBuff, stdout);
	
	        //close(connfd);
	        sleep(3);
    // 	}
	close(connfd);
}
