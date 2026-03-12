#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char **argv){
    int n;
    int fd[2];
    int buf[2048];
    char *data="Hello.. My name is kamal !!";
    pipe(fd);
    write(fd[1],data,strlen(data));
    if((n=read(fd[0],buf,2048))>=0){
        buf[n]='\0';
        printf("%i:%s \n",n,(char *)buf);
    }    
    return 0;
}