#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 6000

int main(int argc, char *argv[])
{
	struct sockaddr_in client1, client2, server;
	char msg[100];
	int fd, len, addr_len, k;
	char name[8][80] = {"vijay", "sushant", "khirod", "manish.sh" , "himanshu" , "aman" , "arpit" , "akhilesh" }; 	
	memset(&client1, 0, sizeof(client1));
	memset(&server, 0, sizeof(server));
	
	//setting for client
	client1.sin_family = AF_INET;
	client1.sin_port = htons(3000);

	client2.sin_family = AF_INET;
	client2.sin_port = htons(5000);

	inet_pton(AF_INET, "127.0.0.1", &client1.sin_addr);
	inet_pton(AF_INET, "127.0.0.1", &client2.sin_addr);

	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd < 0){
		printf("socket error\n");
	}
	// fixig one server port for client1
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);	
	server.sin_port = htons(6000);
	
	if(bind(fd, (struct sockaddr*)&server, sizeof(server)) < 0){
		printf("bind error\n");
		exit(0);
	}
	while(1){
		
		printf("\nReceiving :");
		addr_len = sizeof(client1);
		if((len = recvfrom(fd, msg, 99, 0, (struct sockaddr *)&client1, &addr_len)) < 0){
			perror("recvfrom");
			exit(0);
		}
		k = atoi(msg);
		printf("\nMessage received: %s", msg);
	//	puts("\nEnter message to send: ");
	//	scanf("%s", msg);
		if((len = sendto(fd, name[k], strlen(name[k])+1, 0, (struct sockaddr*)&client2, sizeof(client2))) < 0){	
			perror("sendto");
			exit(0);
		}
	}
	return 0;
}