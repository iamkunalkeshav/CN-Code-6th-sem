#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int server_sockfd, client_sockfd, newsockfd;
	struct sockaddr_in server_address, client_address;
	int clen, slen, i;
	char f = '1';
	char buf[5];
	
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_port = 8000;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	slen = sizeof(server_address);
	
	bind(server_sockfd, (struct sockaddr*) &server_address,slen); 
	listen(server_sockfd,1);
	clen = sizeof(client_address);
	
	newsockfd = accept(server_sockfd, (struct sockaddr*) &client_address,&clen);
	
	while(1)
	{
		sleep(2);
		for(i=0;i<5;i++)
		{
			buf[i] = '\0';
		}
		buf[0] = f;
		send(newsockfd,buf,5,0);
		for(i=0; i<5;i++)
		{
			buf[1] = '\0';
		}
		buf[0]=f;
		recv(newsockfd,buf,5,0);
		printf("FRAME: %s\n",buf);
		
		if(f=='\0')
		{
			f='1';
		}
		else
			f = '0';
	}
	//return 0;
}
	
