#include <stdio.h>
#include <limits.h>

int main(){
    //OPTIMAL
    int q[3]={-1,-1,-1};
    int size=3;
    int req[100]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int req_n=20;

    int curr=-1;
    for(int i=0;i<req_n;i++){
        int inq=0;
        int isfull=1;
        for(int j=0;j<size;j++){
            if(q[j]==req[i]) inq=1;
            if(q[j]==-1) isfull=0;
        }
        if(!inq && !isfull){
            curr=(curr+1)%size;
            q[curr]=req[i];
        }else if(!inq){
            //finding the index with more time of not used
            int max_j=-1;
            int max_j_value=INT_MIN;
            //go through each element in frame
            for(int j=0;j<size;j++){
                //find how soon it is uesd
                int next_use=INT_MAX;
                for(int k=i+1;k<req_n;k++){
                    if(q[j]==req[k]){
                        next_use=k;
                        break;
                    }
                }
                if(next_use>max_j_value){
                    max_j=j;
                    max_j_value=next_use;
                }
            }
            q[max_j]=req[i];
        }
        for(int j=0;j<size;j++){
            printf("%d\t",q[j]);
        }
        printf("\n");
    }
    return 0;
}