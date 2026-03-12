#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_NAME "/tmp/my_fifo"
#define TEN_MEG 1024*1024*10
#define BUFFER_SIZE PIPE_BUF
int main(){
    int fd=open(FIFO_NAME,O_WRONLY); //BLOCK UNTIL READER OPENS
    int byte_sent=0;
    char buffer[BUFFER_SIZE];
    while(byte_sent<TEN_MEG){
        byte_sent+=write(fd,buffer,BUFFER_SIZE);
    }
    printf("%i bytes sent\n",byte_sent);
    return 0;
}