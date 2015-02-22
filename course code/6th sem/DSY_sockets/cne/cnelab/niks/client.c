#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int fd,temp,k,len;
	struct sockaddr_in servaddr;
	char *buf;
	char ch = 'h';
        
 	buf = &ch;
	fd = socket(AF_INET,SOCK_STREAM,0);
	memset(&servaddr, 0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8888);
	servaddr.sin_addr.s_addr = inet_addr("172.20.33.118");

	temp = connect(fd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	
	if(temp == 0)
		printf("Connection successfull\n");
	else {
		printf("Unable to connect to server\n");
		close(fd);
		exit(1);
	}
	k = send(fd,buf,sizeof(buf),0);
       
	close(fd);
	return 0;
}
