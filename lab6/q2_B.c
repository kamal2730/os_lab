#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
    int fd=open("/tmp/my_fifo",O_RDONLY);
    for(int i=1;i<5;i++){
        int k;
        read(fd,&k,sizeof(int));
        printf("%i ",k);
    }
    printf("\n");
    return 0;
}