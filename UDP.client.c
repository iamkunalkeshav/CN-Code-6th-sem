#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>

int main()
{
 int sfd,slen;
 struct sockaddr_in s;
 sfd=socket(AF_INET,SOCK_DGRAM,0);
 s.sin_family=AF_INET;
 s.sin_addr.s_addr=htonl(INADDR_ANY);
 s.sin_port=8888;
 slen=sizeof(s);
 bind(sfd,(struct sockaddr*)&s,slen);
 while(1)
 {
 char ch;
 printf("server on \n");
 recvfrom(sfd,&ch,1,0,(struct sockaddr*)&s,&slen);
 ch++;
 sendto(sfd,&ch,1,0,(struct sockaddr*)&s,slen);
 
 }
 return 0;
 }
