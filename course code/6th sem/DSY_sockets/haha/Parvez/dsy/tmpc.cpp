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
#include<string>
using namespace std; 
#pragma pack(1)
struct node
{
	string s;
};
#pragma pack(0)
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
  serv_addr.sin_port = htons(5004);
  serv_addr.sin_addr.s_addr = inet_addr("172.19.14.65");

  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
  {
	  printf("\n Error : Connect Failed \n");
	  return 1;
  }

struct node nod;
 while(1){
	 // scanf("%s",sbuff);
	  //if(strcmp(sbuff,"end")==0)break;
	  //cout<<strlen(sbuff)<<endl;
	  nod.s="archit";
	  send(sockfd,&nod,sizeof(node),0);
	  getchar();
	 // i++;
  }
  return 0;
}
