#include <stdio.h>
#include <stdlib.h>
int main(){
    int req[8]={98, 183, 37, 122, 14, 124, 65, 67};
    int req_s=8;

    int head=53;
    int THM=0;
    //srtf
    for(int i=0;i<req_s;i++){
        int next=-1;
        int next_val=-1;

        for(int j=0;j<req_s;j++){
            if((next==-1 && req[j]!=-1) || (req[j]!=-1 && (abs(req[next]-head)>abs(req[j]-head)))){
                next=j;
                next_val=req[j];
            }
        }
        THM+=abs(head-req[next]);
        head=req[next];
        req[next]=-1;
    }
    printf("SRTF THM:%d \n",THM);
    return 0;
}