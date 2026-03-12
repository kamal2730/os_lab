#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct mymessage{
    int len;
    char buffer[100][100];
} msg1;
int main(){
    int shm_id=shmget((key_t)27890,sizeof(struct mymessage),0666|IPC_CREAT);
    struct mymessage *msg=(struct mymessage*)shmat(shm_id,NULL,0);
    while(msg->len==0);
    for(int i=0;i<msg->len;i++){
        printf("%s",msg->buffer[i]);
    }
    printf("Recieved %i words\n",msg->len);
    msg->len=0;
    return 0;
}