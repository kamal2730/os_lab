#include <stdio.h>

int main(){
    //FIFO
    int q[3]={-1,-1,-1};
    int size=3;
    int req[100]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int req_n=20;

    int curr=-1;
    for(int i=0;i<req_n;i++){
        int inq=0;
        for(int j=0;j<size;j++){
            if(q[j]==req[i]) inq=1;
        }
        if(!inq){
            curr=(curr+1)%size;
            q[curr]=req[i];
        }
        for(int j=0;j<size;j++){
            printf("%d\t",q[j]);
        }
        printf("\n");
    }
    return 0;
}