#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	int sockfd, newsockfd, portno, k;
	
	FILE *fp;

	socklen_t clilen;

	char filename[256], datasend[256];

	struct sockaddr_in serv_addr, cli_addr;

	int n;

	if (argc < 2) {
		printf("port not defined\n");
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) {
        error("ERROR opening socket");
     }

     bzero((char *) &serv_addr, sizeof(serv_addr));

     portno = atoi(argv[1]);

     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);

     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
              printf("error binding\n");
	      exit(1);
     }

     listen(sockfd,5);

     clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

	if (newsockfd < 0) {
		printf("new socket not created\n");
		exit(1);
	}

	for (k = 0; k < 256; k++) {
		filename[k] = '\0';
		datasend[k] = '\0';
	}

	n = read(newsockfd, filename, 255);
	if (n < 0) {
		printf("error reading file\n");
	}
	fp = fopen(filename, "r");
	if (fp > 0) {
		int i = -1;
		while (datasend[i] != EOF) {
			i++;
			datasend[i] = fgetc(fp);
		}
		datasend[i] = '\0';
		n = write(newsockfd, datasend, strlen(datasend));
		fclose(fp);
		if (n < 0) {
			printf("error writing\n");
			fclose(fp);
		}
	} else {
		printf("file not found\n");
		n = write(newsockfd, "file not found\n", 15);
	}
	close(newsockfd);
	close(sockfd);
	
	return 0;
}
