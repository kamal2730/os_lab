#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
int main(int *argc,char **argv){
    int fd[2];
    int n;
    char *data="Hey kid this is you'r dad\n";
    char buf;
    pipe(fd);
    pid_t pid=fork();
    if(pid==0){
        while((n=read(fd[0],&buf,1)>0)){
            write(STDOUT_FILENO, &buf, 1);
        } 
    }else{
        write(fd[1],data,strlen(data));
    }
    return 0;
}