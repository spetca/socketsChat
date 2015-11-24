#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char *message, server_reply[1000];
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_desc == -1)
	{
		printf("Could not create socket\n");
	}

	server.sin_addr.s_addr = inet_addr("216.58.217.206");
	server.sin_family = AF_INET;
	server.sin_port = htons(80);
	
	if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server))<0)
	{
		printf("connect err\n");
		return 1;
	}

	printf("connected\n");

	message = "GET / HTTP/1.1\r\n\r\n";

	if(send(socket_desc, message, strlen(message),0)<0)
	{
		printf("Send failed\n");
	}
	printf("Data Sned\n");

	if(recv(socket_desc, server_reply,2000,0)<0)
	{
		puts("recv failed");
	}
	puts("reply received\n");
	puts(server_reply);
	return 0;
}

