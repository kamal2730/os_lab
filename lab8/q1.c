#include <stdio.h>
#include <limits.h>
#define NUM_PROCESS 5
#define NUM_RESOURCES 3
int allocation[NUM_PROCESS][NUM_RESOURCES]={
    {0,1,0},
    {2,0,0},
    {3,0,2},
    {2,1,1},
    {0,0,2}
};
int max[NUM_PROCESS][NUM_RESOURCES]={
    {7,5,3},
    {3,2,2},
    {9,0,2},
    {2,2,2},
    {4,3,3}
};
int available[NUM_RESOURCES]={3,3,2};
int need[NUM_PROCESS][NUM_RESOURCES];
int satisfied[NUM_PROCESS];
int main(){
    //need matric
    for(int i=0;i<NUM_PROCESS;i++){
        for(int j=0;j<NUM_RESOURCES;j++){
            need[i][j]=max[i][j]-allocation[i][j];
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    int completed=0;
    while(completed<=NUM_PROCESS){
    for(int i=0;i<NUM_PROCESS;i++){
        int resource_satified=0;
        for(int j=0;j<NUM_RESOURCES;j++){
            if(need[i][j]<=available[j]) resource_satified++;
        }
        if(resource_satified==NUM_RESOURCES){
            completed++;
            for(int j=0;j<NUM_RESOURCES;j++) available[j]+=allocation[i][j];
            printf("P%i\t",i);
        }
    }
    }
    printf("\n");
    
    return 0;
}