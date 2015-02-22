#include <string.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "a6.h"
int main (int argc, char *argv[]) {
  fd_set rdfs;
  int k, sd, newSd, cliLen, n,uu,count = 0;
  char a[100], nam[100];
  char name[200][100];	
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
  cliLen = sizeof(cliAddr);
  newSd = accept(sd, (struct sockaddr *) &cliAddr, &cliLen);
 // recv(newSd, a, 100, 0);
//  printf("recv : %s\n", a); 
  strcpy(name[count++], a);
  char msg[100];
//  printf("%d %s connected", count, a); 
  while(1){
		recv(newSd, a, 100, 0);
    if(decode(a, msg) == 1){
        printf("received %s : \ndecoded to : %s\n", a, msg);
		    send(newSd, "ACK", strlen("ACK")+1, 0);
    }	
}
  close(newSd);
  return 0;
}
