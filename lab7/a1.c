#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define N 5
sem_t stick[N];

void *philosophers(void *args){
    int id=*((int *)(args));
    while(1){
        printf("philosopher %i is thinking\n",id);
        sleep(1);
        if(id==N-1){
            sem_wait(&stick[id]);
            sem_wait(&stick[(id+1)%N]);
        }else{
            sem_wait(&stick[(id+1)%N]);
            sem_wait(&stick[id]);
        }
        
        printf("philosopher %i is eating\n",id);
        sleep(1);
        sem_post(&stick[id]);
        sem_post(&stick[(id+1)%N]);
    }
}

int main(){
    pthread_t phil[N];
    int ids[N];

    for(int i=0;i<N;i++){
        ids[i]=i;
        sem_init(&stick[i],0,1);
        pthread_create(&phil[i],0,&philosophers,(void *)&ids[i]);
    }
    for(int i=0;i<N;i++) pthread_join(phil[i],0);

    for(int i=0;i<N;i++){
        sem_destroy(&stick[i]);
    }
    return 0;
}