#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
	int serv_sockfd,cli_sockfd;
	int serv_len,cli_len;
	char a[100],b[100];
	struct sockaddr_in serv_addr,cli_addr;
	serv_sockfd=socket(AF_INET,SOCK_STREAM,0);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=9002;
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	serv_len=sizeof(serv_addr);
	bind(serv_sockfd,(struct sockaddr*)&serv_addr,serv_len);
	listen(serv_sockfd,5);

	while(1)
	{
		printf("server is waiting.....\n");
		cli_len = sizeof(cli_addr);
		cli_sockfd = accept(serv_sockfd,(struct sockaddr*)&cli_addr,&cli_len);
		read(cli_sockfd, a, sizeof(a));
		printf("reading message from client: ");
		puts(a);
		printf("Enter the message for client: ");
		scanf("%[^\n]s", &b);
		write(cli_sockfd, b, sizeof(b));
		close(cli_sockfd);
	}
	return 0;
}
