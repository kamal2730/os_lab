#include <stdio.h>
#include <limits.h>
int queue[3]={-1,-1,-1};
int request[20]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int queue_curr_size=0;
int main(){
    for(int q=0;q<20;q++){
        printf("request:%d\n",request[q]);
        int inqueue=0;
        for(int i=0;i<3;i++) if(request[q]==queue[i]) inqueue=1;
        if(!inqueue){
            if(queue_curr_size<3){
                queue[queue_curr_size++]=request[q];
            }else{
                //replace the frame which will not be used for longes period of time
                int victim_index=-1;
                int farthest_use=-1;
                for(int i=0;i<3;i++){
                    int next_use=INT_MAX;
                    for(int j=q+1;j<20;j++){
                        if(request[j]==queue[i]){
                            next_use=j;
                            break;
                        }
                    }
                    if(next_use>farthest_use){
                        farthest_use=next_use;
                        victim_index=i;
                    }
                    if(next_use==INT_MAX) break;
                }
                queue[victim_index]=request[q];
            }
            printf("PAGE FAULT\n");
        }else printf("PAGE HIT\n");

        for(int i=0;i<3;i++) printf("%d\t",queue[i]);
        printf("\n\n");

    }
    return 0;
}