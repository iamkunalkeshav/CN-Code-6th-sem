#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
	int serv_sockfd;
	int serv_len;
	struct sockaddr_in serv_address;
	char a[100],b[100];
	serv_sockfd = socket(AF_INET,SOCK_DGRAM,0);
	serv_address.sin_family = AF_INET;
	serv_address.sin_port = 8000;
	serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_len = sizeof(serv_address);
	bind(serv_sockfd, (struct sockaddr*) &serv_address,serv_len);
	printf("server is waiting.... ");
	recvfrom(serv_sockfd, a, sizeof(a), 0, (struct sockaddr*) &serv_address,&serv_len);
	printf("message from client: ");
	puts(a);
	printf("message from server: ");
	gets(b);
	sendto(serv_sockfd, b, sizeof(b), 0, (struct sockaddr*) &serv_address,serv_len);
	close(serv_sockfd);
	return 0;
}
