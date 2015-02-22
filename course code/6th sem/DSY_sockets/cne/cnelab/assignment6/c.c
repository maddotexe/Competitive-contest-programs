#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include "a6.h"
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
  
  if(h==NULL) {
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
  if(rc<0) {
    printf("connection refused");
    exit(1);
  }
// printf("Enter your name :");
//  fgets(name, 100, stdin);
 // send(sd, name, strlen(name)+1, 0);
		
  readfile(sd);
	
return 0;
  
}
