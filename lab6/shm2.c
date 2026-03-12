#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#define BUFF 100
struct my_message{
    int status;
    char buf[BUFF];
} msg;
int main(){
    int shm_id=shmget((key_t)2730,sizeof(struct my_message),0666 | IPC_CREAT);
    struct my_message* memory=shmat(shm_id,0,0);
    while(1){
        if(memory->status==1){
            printf("recv:%s",memory->buf);
            memory->status=0;
        }
    }
    shmdt(memory);
    return 0;
}