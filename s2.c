#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	int sd,nsd, c;
	sd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server, client;
	char *message;
	if(sd == -1)
	{
		printf("could not create socket\n");
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	if(bind(sd, (struct sockaddr *)&server, sizeof(server))<0)
	{
		puts("bind failed");
	}
	puts("bind complete");

	listen(sd, 3);
	
	puts("waiting for incoming connection...");
	c = sizeof(struct sockaddr_in);
	while(nsd = accept(sd, (struct sockaddr *)&client, (socklen_t*)&c) )
	{

		puts("Connection accepted");
	
		message = "hello client, have rx ur msg, g2g lol";
		write(nsd, message, strlen(message));
	}
	if(nsd <0)
	{
		puts("accept failed");
		return 1;
	}
	return 0;
}

