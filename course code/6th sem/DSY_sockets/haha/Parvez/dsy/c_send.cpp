#include <sys/socket.h>
#include<bits/stdc++.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
using namespace std; 
int main(void)
{
  int sockfd = 0,n = 0;
  char sbuff[1025],rbuff[1024];
  struct sockaddr_in serv_addr;
 
  memset(rbuff, '0' ,sizeof(rbuff));
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
      printf("\n Error : Could not create socket \n");
      return 1;
    }
 
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(5001);
  serv_addr.sin_addr.s_addr = inet_addr("172.19.14.55");

  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
  {
	  printf("\n Error : Connect Failed \n");
	  return 1;
  }

 while(1){
	  scanf("%s",sbuff);
	  if(strcmp(sbuff,"end")==0)break;
	  //cout<<strlen(sbuff)<<endl;
	  send(sockfd,sbuff,strlen(sbuff),0);
	 // i++;
  }
  return 0;
}
