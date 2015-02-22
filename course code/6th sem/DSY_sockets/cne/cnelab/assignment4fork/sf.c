#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]) {
  int k, sd, newSd, cliLen, n,uu;
  char a[100];
  char name[8][80] = {"NIKHIL", "SAURABH", "AYUSH", "SHREYA" , "KARTIKEYA" , "AASHIMA" , "VIVEK" , "SEJAL" }; 
  struct sockaddr_in cliAddr, servAddr;
  char line[100];
  sd = socket(AF_INET, SOCK_STREAM, 0);
   if(sd<0) {
    return 0;
  }
  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servAddr.sin_port = htons(atoi(argv[1]));
   
  if(bind(sd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
    return 0;
  }
  listen(sd,5);
    while(1){
    	cliLen = sizeof(cliAddr);
   	newSd = accept(sd, (struct sockaddr *) &cliAddr, &cliLen);
	if(fork() == 0){
		close(sd);
		while(1){
   	 		n = recv(newSd, a, 100, 0);
			k = atoi(a);
			printf("received: %d\n", k); 
			uu = send(newSd, name[k], strlen(name[k])+1, 0);
		}
	}    
    	close(newSd);
    }
    
return 0;
}
  
  
