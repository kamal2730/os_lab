#include <stdio.h>
#include <limits.h>
#define FRAME_SIZE 3
#define REQUEST_SIZE 20
struct frame{
    int frame_id;
    unsigned char refernce_bit;
} FRAMES[FRAME_SIZE];

int request[20]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
void update_frames(int hit_index){
    for(int i=0;i<FRAME_SIZE;i++){
        FRAMES[i].refernce_bit >>= 1;
        if(i==hit_index) FRAMES[i].refernce_bit|=0x80;
    }
}
int find_victim(){
    int victim=0;
    for(int i=0;i<FRAME_SIZE;i++){
        if(FRAMES[i].refernce_bit<FRAMES[victim].refernce_bit) victim=i;
    }
    return victim;
}
int main(){
    //initialize frames
    for(int i=0;i<FRAME_SIZE;i++){
        FRAMES[i].frame_id=-1;
        FRAMES[i].refernce_bit=0;
    }
    int frame_count=0;
    for(int q=0;q<REQUEST_SIZE;q++){
        int inqueue=0;
        int usued_frame;
        for(int i=0;i<FRAME_SIZE;i++){
            if(FRAMES[i].frame_id==request[q]){
                inqueue=1;
                usued_frame=i;
                break;
            }
        }
        if(!inqueue){
            //find victim
            if(frame_count<FRAME_SIZE){
                FRAMES[frame_count++].frame_id=request[q];
                usued_frame=(frame_count-1);
            }else{
                int victim=find_victim();
                FRAMES[victim].frame_id=request[q];
                FRAMES[victim].refernce_bit=0;
                usued_frame=(victim);
            }
            printf("PAGEFAULT\n");
        }else{
            printf("PAGEHIT\n");
        }
        update_frames(usued_frame);
        for(int i=0;i<FRAME_SIZE;i++){
            printf("%i\t",FRAMES[i].frame_id);
            printf(":%b\n",FRAMES[i].refernce_bit);
        }
        printf("\n\n");
        
    }
    return 0;
}