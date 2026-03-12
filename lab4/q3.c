#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	pid_t pid =fork();
	if(pid==0){
		exit(1);
	}else{
		sleep(30);
	}
	return 0;
}
