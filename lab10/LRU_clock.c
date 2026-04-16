#include <stdio.h>
#define FRAME_SIZE 3
#define REQUEST_SIZE 20

struct frame{
    int frame_id;
    int bit;
} FRAMES[FRAME_SIZE];

int request[20]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int hand=0;
int main(){
    int frame_curr_size=0;
    for(int q=0;q<REQUEST_SIZE;q++){
        printf("PAGE REQUEST:%i\n",request[q]);
        int inqueue=0;
        for(int j=0;j<FRAME_SIZE;j++){
            if(FRAMES[j].frame_id==request[q]){
                FRAMES[j].bit=1;
                inqueue=1;
            }
        }
        if(!inqueue){
            if(frame_curr_size<3){
                FRAMES[frame_curr_size].frame_id=request[q];
                FRAMES[frame_curr_size].bit=1;
                frame_curr_size++;
            }else{
                while(1){
                    if(FRAMES[hand].bit==0){
                        FRAMES[hand].frame_id=request[q];
                        FRAMES[hand].bit=1;
                        hand++;
                        hand=hand%FRAME_SIZE;
                        break;
                    }else{
                        FRAMES[hand].bit=0;
                    }
                    hand++;
                    hand=hand%FRAME_SIZE;
                }
            }
            printf("PAGEFAULT\n");
        }else{
            printf("PAGEHIT\n");
        }
        for(int j=0;j<FRAME_SIZE;j++){
            printf("%d\t:\t%d\n",FRAMES[j].frame_id,FRAMES[j].bit);
        }
        printf("\n\n");
    }
    return 0;
}