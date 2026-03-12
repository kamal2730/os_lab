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
        int k=msgrcv(msg_id,(void *)&msg1,BUFFER_SIZE,0,0);
        int flag=1;
        int n=strlen(msg1.buffer);
        if(msg1.buffer[n-1] == '\n')
            msg1.buffer[n-1] = '\0';
            n=strlen(msg1.buffer);
        int i=0;
        int j=n-1;
        while(i<j){
            if(msg1.buffer[i]!=msg1.buffer[j]){
                flag=0;
                break;
            }
            i++;
            j--;
        }
        printf("%s\n",((flag==1)?"palindrome":"not palindrome"));
    }
    return 0;
}