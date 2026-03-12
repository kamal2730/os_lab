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
    msg->len=0;
    printf("n:");
    int n;
    scanf(" %i",&n);
    for(int i=0;i<(n+1);i++){
        fgets(msg->buffer[i],100,stdin);
    }
    printf("sending %i words\n",n);
    msg->len=n+1;
    return 0;
}