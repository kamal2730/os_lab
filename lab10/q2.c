#include <stdio.h>

typedef struct Q{
    int v;
    int last_used;
}Q;

//THere is some edge case problem fig it out 

int main(){
    int size=3;
    int req[100]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int req_n=20;

    Q q[3]={{-1,0},{-1,0},{-1,0}};
    int curr=0;

    int page_fault=0;
    for(int i=0;i<req_n;i++){
        int inq=0;
        int isfull=1;
        for(int j=0;j<size;j++){
            if(q[j].v==req[i]){
                inq=1;
                q[j].last_used=i;
                break;
            }
            if(q[j].v==-1) isfull=0;
        }
        if(!isfull){
            q[curr].v=req[i];
            q[curr].last_used=i;
            curr=(curr+1)%size;
            page_fault++;
        }else if(!inq){
            int victim=0;
            int min_time=q[0].last_used;
            for(int j=0;j<size;j++){
                if(min_time>q[j].last_used){
                    victim=j;
                    min_time=q[j].last_used;
                }
            }
            q[victim].v=req[i];
            q[victim].last_used=i;
            page_fault++;
        }
        for(int j=0;j<size;j++){
            printf("%d\t",q[j].v);
        }
        printf("\n");
    }
    printf("pf:%d\n",page_fault);
    return 0;
}

