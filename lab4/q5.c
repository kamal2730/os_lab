#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <strings.h>
void *fib(void* num){
	int n=atoi(num);
	int *arr=(int *)malloc(sizeof(int)*n);
	arr[0]=1;
	arr[1]=1;
	for(int i=2;i<n;i++){
		arr[i]=arr[i-1]+arr[i-2];
	}
	return arr;

}

int main(int argc,char* argv[]){
	pthread_t thread;
	pthread_create(&thread,0,&fib,(void*)argv[1]);
	int *arr;
	pthread_join(thread,(void **)&arr);
	for(int i=0;i<atoi(argv[1]);i++){
		printf("%i ",arr[i]);
	}
	printf("\n");
	return 0;
}

