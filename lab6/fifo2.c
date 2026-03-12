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
    int fd=open(FIFO_NAME,O_RDONLY); //BLOCK UNTIL WRITER OPENS
    int byte_sent=0;
    char buffer[BUFFER_SIZE];
    while(byte_sent<TEN_MEG){
        byte_sent+=read(fd,buffer,BUFFER_SIZE);
    }
    printf("%i bytes recieved\n",byte_sent);
    return 0;
}