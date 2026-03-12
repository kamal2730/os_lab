#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define PARENT_SENT 'X'
struct mymessage{
    int sentp;
    int sentc;
} msg1;
int main(){
    int shm_id=shmget((key_t)2730,sizeof(struct mymessage),0666|IPC_CREAT);
    struct mymessage *msg=(struct mymessage*)shmat(shm_id,NULL,0);
    msg->sentp=0;
    msg->sentc=0;
    pid_t pid=fork();
    if(pid==0){
        while(msg->sentp==0);
        printf("Child recieved:%c\n",msg->sentp);
        msg->sentc=msg->sentp+1;
    }else{
        msg->sentp=PARENT_SENT;
        while(msg->sentc==0);
        printf("Parent recieved:%c\n",msg->sentc);
    }
    return 0;
}