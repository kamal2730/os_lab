#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
    int fd=open("/tmp/my_fifo",O_WRONLY);
    int nums[4]={567,99,78,69};
    for(int i=0;i<4;i++){
        write(fd,&nums[i],sizeof(int));
    }
    return 0;
}