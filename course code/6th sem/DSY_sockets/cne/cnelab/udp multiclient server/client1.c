#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


int main(int argc, char *argv[])
{
	struct sockaddr_in client1, server;
	char msg[100];
	int fd, len, addr_len;
	memset(&client1, 0, sizeof(client1));
	memset(&server, 0, sizeof(server));
	
	//setting for client
	client1.sin_family = AF_INET;
	client1.sin_port = htons(6000);
	inet_pton(AF_INET, "127.0.0.1", &client1.sin_addr);

	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd < 0){
		printf("socket error\n");
	}
	// fixig one server port for client1
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);	
	server.sin_port = htons(3000);
	
	if(bind(fd, (struct sockaddr*)&server, sizeof(server)) < 0){
		printf("bind error\n");
		exit(0);
	}
	while(1){
		
		
		puts("\nEnter message to send: ");
		scanf("%s", msg);
		if((len = sendto(fd, msg, strlen(msg)+1, 0, (struct sockaddr*)&client1, sizeof(client1))) < 0){	
			perror("sendto");
			exit(0);
		}
	/*	printf("\nReceiving...");
		printf("\nMessage received: %s", msg);
		addr_len = sizeof(client1);
		if((len = recvfrom(fd, msg, 99, 0, (struct sockaddr *)&client1, &addr_len)) < 0){
			perror("recvfrom");
			exit(0);
		}*/
	}
	close(fd);
	return 0;
}