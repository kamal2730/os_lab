#include <stdio.h>
#define NUM_SEGMENTS
//start_addr, limit
int segmentation_table[NUM_SEGMENTS][2]={
    {1400,1000},
    {6300,400},
    {4300,400},
    {3200,1100},
    {4700,1000}
};
void calculate_addr(int segment_id,int offset){
    if(offset>segmentation_table[segment_id][1]){
        printf("segmentation fault\n");
        return;
    }
    printf("addr:%d\n",segmentation_table[segment_id][0]+offset);
}
int main(){
    calculate_addr(2,53);
    calculate_addr(3,852);
    calculate_addr(0,1222);
    return 0;
}