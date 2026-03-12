#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	pid_t child;
	child = fork();
	if(child<0){
		printf("fork failed!");
	}else if(child==0){
		printf("this is child process with pid:%i and ppid:%i \n",getpid(),getppid());
		exit(0);
	}else{
		printf("this is parent with pid:%i and ppid:%i \n",getpid(),getppid());
		wait(NULL);
	}
	return 0;
}
