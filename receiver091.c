#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>

struct message{
	long mtype;
	char mtext[100];
};

int main(){
	int msgid,len=20;
	key_t key;
	struct message buff;
	key=131;
	msgid = msgget(key, IPC_CREAT|0666);
	printf("\n q=%d\n",msgid);
	if(msgrcv(msgid, &buff, len, 0, 0)==-1)
	{
	   perror("msg receive Failed");
	   exit(1);
	}
	printf("Message received: %s\n",buff.mtext);
	return 0;
}
