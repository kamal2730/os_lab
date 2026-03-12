#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>

#define BUFSIZE 1024

struct my_message{
    long int message_type;
    char msg[BUFSIZE];
} msg;
int main(int argc,char **argv){
    int qid=msgget((key_t)2730,0666 | IPC_CREAT);
    while(1){
        msgrcv(qid,&msg,BUFSIZE,0,0);
        printf("Message rcv:%s \n",msg.msg);
    }
    return 0;
}