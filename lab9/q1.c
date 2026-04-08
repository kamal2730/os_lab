#include <stdio.h>
#include <limits.h>
//memory partitions
//count
//order
int main(){
    int n=5;
    int req[5]={212,417,112,426};

    int p1[5]={100,500,200,300,600};
    printf("FIRST FIT\n");
    //first-fit
    for(int i=0;i<4;i++){
        int flag=0;
        for(int j=0;j<5;j++){
            if(p1[j]>=req[i]){
                p1[j]-=req[i];
                flag=1;
                break;
            }
        }
        if(!flag){
            printf("can't allocate : %d \n",req[i]);
        }
    }
    for(int i=0;i<5;i++){
        printf("%d ",p1[i]);
    }
    printf("\n");

    printf("\nBEST FIT\n");
    int p2[5]={100,500,200,300,600};
    //Best-fit
    for(int i=0;i<4;i++){
        int min=INT_MAX;
        for(int j=0;j<5;j++){
            if(p2[j]>=req[i]){
                if(min==INT_MAX) min=j;
                else if(p2[j]<p2[min]) min=j;
            }
        }
        if(min==INT_MAX){
            printf("Best fit failed at %d \n",req[i]);
            break;
        }
        p2[min]-=req[i];
    }
    for(int i=0;i<5;i++){
        printf("%d ",p2[i]);
    }
    printf("\n");


    printf("\nWORST FIT\n");
    int p3[5]={100,500,200,300,600};
    //Worst-fit
    for(int i=0;i<4;i++){
        int max=INT_MIN;
        for(int j=0;j<5;j++){
            if(p2[j]>=req[i]){
                if(max==INT_MIN) max=j;
                else if(p2[j]>p2[max]) max=j;
            }
        }
        if(max==INT_MIN){
            printf("Worst fit failed at %d \n",req[i]);
            break;
        }
        p2[max]-=req[i];
    }
    for(int i=0;i<5;i++){
        printf("%d ",p2[i]);
    }
    printf("\n");

    return 0;
}