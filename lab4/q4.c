#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int arr[100];
int n;

void *sort1(void* arg){
	
}
void *sort2(void* arg){

}
int main(int argc,char *argv[]){
	n=atoi(argv[1]);
	for(int i=0;i<n;i++){
		arr[i]=atoi(argv[i+2]);
	}
	printf("n:%i\n",n);
	for(int i=0;i<n;i++){
		printf("%i ",arr[i]);
	}
	printf("\n");
	return 0;
}
