//LFU 2 BIT
#include <stdio.h>
#define FRAME_SIZE 3
struct frame{
    int id;
    int R;
    int M;
};
struct frame FRAMES[FRAME_SIZE]={{-1,0,0},{-1,0,0},{-1,0,0}};

int hand=0;

int find_victim(){
    int victim;
    for(int i=0;i<FRAME_SIZE;i++){
        if(FRAMES[hand].R==0 && FRAMES[hand].M==0){
            victim=hand;
            hand=(hand+1)%FRAME_SIZE;
            return victim;
        }
        hand=(hand+1)%FRAME_SIZE;
    }
    for(int i=0;i<FRAME_SIZE;i++){
        if(FRAMES[hand].R==0 && FRAMES[hand].M==1){
            victim=hand;
            hand=(hand+1)%FRAME_SIZE;
            return victim;
        }
        FRAMES[hand].R=0;
        hand=(hand+1)%FRAME_SIZE;
    }
    return find_victim();
}
int request[20]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int curr_frame_size=0;
int main(){
    int hit=0;
    for(int q=0;q<20;q++){
        printf("Requested:%d\n",request[q]);
        int found=0;
        for(int i=0;i<FRAME_SIZE;i++){
            if(FRAMES[i].id==request[q]){
                found=1;
                FRAMES[i].R=1;
                break;
            }
        }
        if(!found){
            if(curr_frame_size<FRAME_SIZE){
                FRAMES[curr_frame_size].id=request[q];
                FRAMES[curr_frame_size].R=1;
                FRAMES[curr_frame_size].M=0;
                curr_frame_size++;
            }else{
                //finding victim
                int victim=find_victim();
                FRAMES[victim].id=request[q];
                FRAMES[victim].R=1;
                FRAMES[victim].M=1;
            }
            printf("PAGE MISS\n");
        }else{
            printf("PAGE HIT\n");
            hit++;
        }
        for(int i=0;i<FRAME_SIZE;i++) printf("%d\t",FRAMES[i].id);
        printf("\n\n");
        printf("HIT:%i/%\n",hit*100/20);
    }
    
    return 0;
}