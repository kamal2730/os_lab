#include <stdio.h>
#define NUM_PROCESS 5
#define NUM_RESOURCES 3

int available[NUM_PROCESS]={0,0,0};
int max[NUM_PROCESS][NUM_RESOURCES]={
    {0,1,0},
    {2,0,1},
    {3,0,3},
    {2,1,1},
    {0,0,2}
};
int allocation[NUM_PROCESS][NUM_RESOURCES]={
    {0,0,0},
    {2,0,2},
    {0,0,0},
    {1,0,0},
    {0,0,2}
};

// int allocation[NUM_PROCESS][NUM_RESOURCES]={
//     {0,1,0},
//     {2,0,0},
//     {3,0,2},
//     {2,1,1},
//     {0,0,2}
// };
// int max[NUM_PROCESS][NUM_RESOURCES]={
//     {7,5,3},
//     {3,2,2},
//     {9,0,2},
//     {2,2,2},
//     {4,3,3}
// };
// int available[NUM_RESOURCES]={3,3,2};

int need[NUM_PROCESS][NUM_RESOURCES];
int main(){
    for(int i=0;i<NUM_PROCESS;i++){
        for(int j=0;j<NUM_RESOURCES;j++){
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    //safety algorithm
    int completed[NUM_PROCESS];
    for(int i=0;i<NUM_PROCESS;i++) completed[i]=0;

    int completed_cnt=0;

    while(completed_cnt<NUM_PROCESS){
        int progress=0;
        for(int i=0;i<NUM_PROCESS;i++){
            if(completed[i]) continue;
            int satisfy_count=0;
            for(int j=0;j<NUM_RESOURCES;j++){
                if(need[i][j]<=available[j]){
                    satisfy_count++;
                }
            }
            if(satisfy_count==NUM_RESOURCES){
                progress++;
                completed_cnt++;
                completed[i]=1;
                for(int j=0;j<NUM_RESOURCES;j++){
                    available[j]+=allocation[i][j];
                    need[i][j]=0;
                }
                printf("COMPLETED P%i\n",i);
                    
            }
        }
        if(!progress){
            printf("DEADLOCKKKKK !\n");
            break;
        }
    }
    return 0;
}