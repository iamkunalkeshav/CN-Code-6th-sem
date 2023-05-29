#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
	int sockfd;
	int len;
	struct sockaddr_in address;
	char ch[100];
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	address.sin_family = AF_INET;
	address.sin_port = 8002;
	address.sin_addr.s_addr = inet_addr("10.10.9.251");
	len = sizeof(address);
	bind(sockfd, (struct sockaddr*) &address,len);
	while(1)
	{
		printf("Enter the message: ");
		gets(ch);
		sendto(sockfd, ch, sizeof(ch), 0, (struct sockaddr*) &address,len);
		recvfrom(sockfd, ch, sizeof(ch), 0, (struct sockaddr*) &address,&len);
		printf("message from server: ");
		puts(ch);
	}
	//close(sockfd);
	return 0;
}
	
