#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int serv_sockfd, slen, clen, newsockfd;
	struct sockaddr_in saddr,caddr;
	char str[100];
	serv_sockfd = socket(AF_INET,SOCK_STREAM,0);
	saddr.sin_family = AF_INET;
	saddr.sin_port = 6000;
	saddr.sin_addr.s_addr = INADDR_ANY;
	slen = sizeof(saddr);
	bind(serv_sockfd, (struct sockaddr*) &saddr,slen);
	listen(serv_sockfd, 5);
	while(1)
	{
		clen = sizeof(caddr);
		newsockfd = accept(serv_sockfd, (struct sockaddr*) &caddr, &clen);
		if(newsockfd < 0)
		{
			printf("Accept error\n");
			exit(0);
		}
		
		if(fork() == 0)
		{
			close(serv_sockfd);
			
			//recvfrom(serv_sockfd, str, sizeof(str), 0, (struct sockaddr*) &saddr,&slen);
			//printf("message from client: ");
			//puts(str);
			read(newsockfd, str, sizeof(str));
			printf("%s\n", str);
			int n, i, temp;
			n = strlen(str);
			for(i=0; i<n/2; i++)
			{
				temp = str[i];
				str[i] = str[n-i-1];
				str[n-i-1] = temp;
			}
			write(newsockfd, str, sizeof(str));
			//close(serv_sockfd);
			
			close(newsockfd);
			exit(0);
		}
	}
	return 0;
}
