#include <stdio.h>
int q[100];
int front=0;
int last=0;
int size=3;

int main(){
    //FIFO
    int req[100]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int req_n=20;
    for(int i=0;i<req_n;i++){
        int inq=0;
        for(int j=front;j<last;j++){
            if(q[j]==req[i]) inq=1;
        }
        if(!inq && (last-front)<size){
            q[last++]=req[i];
        }else if(!inq){
            q[last++]=req[i];
            front++;
        }
        for(int j=front;j<last;j++){
            printf("%d\t",q[j]);
        }
        printf("\n");
    }

    return 0;
}