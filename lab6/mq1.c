#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    msg.message_type=1;
    while(1){
        fgets(msg.msg,BUFSIZE,stdin);
        msgsnd(qid,&msg,BUFSIZE,0);
        printf("\n");
    }
    // strcpy(msg.msg,"HELLOO MY NAME IS KAMAL");
    return 0;
}