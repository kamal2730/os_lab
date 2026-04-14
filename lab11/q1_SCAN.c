#include <stdio.h>
#include <stdlib.h>
int main(){
    int req[8]={98, 183, 37, 122, 14, 124, 65, 67};
    int req_s=8;

    int head=53;
    int THM=0;
    int x=1; //direction

    //sort
    for(int i=0;i<req_s;i++){
        for(int j=i+1;j<req_s;j++){
            if(req[j]<req[i]){
                int temp=req[i];
                req[i]=req[j];
                req[j]=temp;
            }
        }
    }
    //SCAN
    int mid_index=-1;
    for(int i=0;i<req_s;i++){
        if(req[i]>=head){
            mid_index=i;
            break;
        }
    }
    //first direction
    for(int i=mid_index-1;i>=0;i--){
        THM+=abs(head-req[i]);
        head=req[i];
    }
    THM+=abs(head-0);
    head=0;
    for(int i=mid_index;i<req_s;i++){
        THM+=abs(head-req[i]);
        head=req[i];
    }
    printf("THM:%d\n",THM);
    return 0;
}