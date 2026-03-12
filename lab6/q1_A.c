#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#define BUFFER_SIZE 1024
struct msg{
    long int msg_type;
    char buffer[1024];
}msg1;
int main(){
    int msg_id=msgget((key_t)2730,0666|IPC_CREAT);
    msg1.msg_type=1;
    while(1){
        fgets(msg1.buffer,BUFFER_SIZE,stdin);
        msgsnd(msg_id,(void *)&msg1,BUFFER_SIZE,0);
    }
    return 0;
}