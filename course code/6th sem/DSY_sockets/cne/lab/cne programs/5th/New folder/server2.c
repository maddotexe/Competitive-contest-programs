#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd,temp,k,new_fd,new_fd1;
	char buf[1000];
	fd_set rdfs;
	struct sockaddr_in myaddr,client1,client2;
	socklen_t fromlen;

	memset(&myaddr, 0, sizeof(myaddr));
	fd = socket(AF_INET,SOCK_STREAM,0);
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(8888);
	myaddr.sin_addr.s_addr = INADDR_ANY;

	temp = bind(fd,(struct sockaddr *)&myaddr,sizeof(myaddr));
	if(temp == -1) {
		printf("can't bind\n");
		close(fd);
		exit(1);
	}

	temp = listen(fd,5);

	if(temp == -1) {
		printf("Can't listen\n");
		close(fd);
		exit(1);
	}
	memset(&client1, 0, sizeof(client1));

	fromlen = sizeof(client1);
		
	new_fd = accept(fd,(struct sockaddr *)&client1,&fromlen);
        if(new_fd == -1) {
                printf("Can't accept connections");
                close(fd);
                exit(1);
        }
	while (1) {
		FD_ZERO(&rdfs);
		FD_SET(0,&rdfs);
		FD_SET(new_fd,&rdfs);
		select(new_fd+1,&rdfs,NULL,NULL,NULL);
		if(FD_ISSET(new_fd,&rdfs)) {
			k=recv(new_fd,buf,sizeof(buf),0); 						
            puts(buf);	
		}
		if(FD_ISSET(0,&rdfs)) {
			gets(buf);
			k=send(new_fd,buf,sizeof(buf),0);
		}
	}
	
	return 0;
}