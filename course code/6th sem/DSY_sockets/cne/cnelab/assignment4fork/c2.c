
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

int main (int argc, char *argv[]) {
	
  char str[100];
  int sd, rc, i,kk;
  struct sockaddr_in localAddr, servAddr;
  struct hostent *h;
  
  bzero(&localAddr, sizeof(localAddr));
  bzero(&servAddr, sizeof(servAddr));

  if(argc < 3) {
    exit(0);
  }

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

   while(1){
    fgets(str, 100, stdin);
    rc = send(sd, str, strlen(str)+1, 0);
    kk = recv(sd,str,100,0);
    printf("%s", str);
   }
    if(rc<0) {
      close(sd);
      exit(1);
    
    }
   
  

return 0;
  
}
