#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

int main (int argc, char *argv[]) {
	fd_set rdfs;	
	char str[100], k[100],name[100];
	int sd, rc, i,kk;
	struct sockaddr_in localAddr, servAddr;
	struct hostent *h;
	  
	bzero(&localAddr, sizeof(localAddr));
	bzero(&servAddr, sizeof(servAddr));

	if(argc < 3) {
		exit(0);
	}
	// printf("First enter your name : ");
	// fgets(name, 100, stdin);
	  
	h = gethostbyname(argv[1]);
	  
	if(h == NULL) {
		printf("error\n");
		exit(0);
	}

	servAddr.sin_family = AF_INET;
	memcpy((char*) &servAddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
	servAddr.sin_port = htons(atoi(argv[2]));

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd < 0) {
		perror("cannot open socket ");
		exit(0);
	}
	localAddr.sin_family = AF_INET;
	localAddr.sin_port = htons(0);
	 
	rc = bind(sd, (struct sockaddr *) &localAddr, sizeof(localAddr));
	if(rc < 0) {
		printf("bind error");
		exit(0);
	}
				
	rc = connect(sd, (struct sockaddr *) &servAddr, sizeof(servAddr));
	if(rc < 0) {
		printf("connection refused");
		exit(1);
	}
	// printf("Enter your name :");
	//  fgets(name, 100, stdin);
	send(sd, name, strlen(name)+1, 0);
			
	while(1){
		FD_ZERO(&rdfs);
		FD_SET(0, &rdfs);
		FD_SET(sd, &rdfs);

		select(sd+1, &rdfs, NULL, NULL, NULL);
		if(FD_ISSET(sd, &rdfs)){
			recv(sd, k, 100, 0);
			printf("recv : %s\n", k); 
		}
		if(FD_ISSET(0, &rdfs)){
			fgets(k, 100, stdin);
			send(sd, k, strlen(k)+1, 0);
		}
	}
	
	return 0;
}
