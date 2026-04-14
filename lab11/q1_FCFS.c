#include <stdio.h>
#include <stdlib.h>
int main(){
    int req[8]={98, 183, 37, 122, 14, 124, 65, 67};
    int req_s=8;

    int head=53;
    int THM=0;
    //fcfs
    for(int i=0;i<req_s;i++){
        THM+=abs(head-req[i]);
        head=req[i];
    }
    printf("FCFS THM:%d \n",THM);
    return 0;
}