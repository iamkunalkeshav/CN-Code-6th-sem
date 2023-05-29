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
	int sockfd;
	struct sockaddr_in address;
	int slen,i;
	char buf[5];
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_port = 8000;
	address.sin_addr.s_addr = inet_addr("10.10.10.5");
	slen = sizeof(address);
	
	bind(sockfd, (struct sockaddr*) &address,slen); 
	connect(sockfd, (struct sockaddr*) &address,slen);
	 while(1)
	 {
	 	sleep(2);
	 	for(int i=0; i<5; i++)
	 	{
	 		buf[i] = '\0';
	 	}
	 	
	 	
	 	recv(sockfd,buf,5,0);
	 	printf("ACK :%s\n",buf);
	 	
	 	if(buf[0] == '0')
	 	{
	 		buf[0] = '1';
	 	}
	 	else
	 		buf[0] = '0';
	 	send(sockfd,buf,5,0);
	 }
	 return 0;
	 
}
	 	
