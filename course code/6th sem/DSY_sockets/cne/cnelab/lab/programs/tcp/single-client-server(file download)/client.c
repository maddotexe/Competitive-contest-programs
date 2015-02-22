#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	int sockfd, portno, n, k;

	struct sockaddr_in client;

	char filename[256], datasent[256], ack[256];

	FILE *fp;

	if (argc < 2) {
		printf("port not defined\n");
		exit(1);
	}

	portno = atoi(argv[1]);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) {
        error("ERROR opening socket");
    	}

    

    	bzero((char *) &client, sizeof(client));

    	client.sin_family = AF_INET;
    	client.sin_addr.s_addr = inet_addr("127.0.0.1");
    	client.sin_port = htons(portno);

    	if (connect(sockfd,(struct sockaddr *) &client,sizeof(client)) < 0) {
        error("ERROR connecting");
    	}

    	for (k = 0; k < 256; k++) {
	    filename[k] = '\0';
	    datasent[k] = '\0';
	    ack[k] = '\0';
    	}

	printf("write filename : ");
	gets(filename);
	n = write(sockfd, filename, strlen(filename));
	n = read(sockfd, ack, 255);
	if (n < 0) {
		printf("error reading ack\n");
	}
	if (strcmp(ack, "file not found\n")) {
	fp = fopen(filename, "w");
	fprintf(fp, "%s", ack);
	fclose(fp);
	printf("%s has been downloaded\n", filename);
	} else {
		printf("file not found\n");
	}
	close(sockfd);
	return 0;
}
