
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUCCESS 0
#define ERROR   1
int main (int argc, char *argv[]) {
  int sd, newSd, cliLen, n,uu;
	char a[100];
  struct sockaddr_in cliAddr, servAddr;
  char line[100];
  sd = socket(AF_INET, SOCK_STREAM, 0);
   if(sd<0) {
    return ERROR;
  }
  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servAddr.sin_port = htons(atoi(argv[1]));
   
  if(bind(sd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
    return ERROR;
  }
  listen(sd,5);
  while(1) {
    cliLen = sizeof(cliAddr);
    newSd = accept(sd, (struct sockaddr *) &cliAddr, &cliLen);
    while(1){
 //   	n = recv(newSd, a, 100, 0);
   //	 printf("%s", a);
	 scanf("%s", a);
	 uu = send(newSd, a, strlen(a)+1, 0);
    }	close(newSd);
    
  } 
return 0;
}
  
  
