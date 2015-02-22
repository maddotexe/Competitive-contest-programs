#include <string.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

int main (int argc, char *argv[]) {
	fd_set rdfs;
	int k, sd, newSd, cliLen, n,uu,count = 0;
	char a[100], nam[100];
	char name[200][100];	
	struct sockaddr_in cliAddr, servAddr;
	char line[100];
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd < 0) {
		return 0;
	}
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(argv[1]));
	   
	if(bind(sd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
		return 0;
	}
	listen(sd,5);
	cliLen = sizeof(cliAddr);
	while(1){
		newSd = accept(sd, (struct sockaddr *) &cliAddr, &cliLen);
		recv(newSd, a, 100, 0);
		printf("recv : %s\n", a); 
		strcpy(name[count++], a);
		printf("%d %s connected", count, a); 
		if(fork() == 0){
			close(sd);	
			while(1){
				FD_ZERO(&rdfs);
				FD_SET(0, &rdfs);
				FD_SET(newSd, &rdfs);
				
				select(newSd+1, &rdfs, NULL, NULL, NULL);
				if(FD_ISSET(newSd, &rdfs)){
					recv(newSd, a, 100, 0);
					printf("recv : %s\n", a); 

				}
				if(FD_ISSET(0, &rdfs)){
					fgets(nam, 100, stdin);
					send(newSd, nam, strlen(nam)+1, 0);
				}
			}  
		} 
		
	}
	  close(newSd);
	return 0;
}
