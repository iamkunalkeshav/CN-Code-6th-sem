#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
	int sockfd,len,result;
	char name[100],ser[100];
	struct sockaddr_in address;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_port=9002;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");

	len=sizeof(address);
	result=connect(sockfd,(struct sockaddr*)&address,len);
	if(result == -1)
	{
		perror("unable to connect\n");
		exit(1);
	}
	printf("Enter the message: ");
	gets(name);
	write(sockfd,name,sizeof(name));
	read(sockfd,ser,sizeof(ser));
	printf("Reading from server: ");
	puts(ser);
	close(sockfd);
	return 0;
}
