#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFF 10
#define N 20
int f=-1,r=-1;
int count=0;
sem_t full,empty,mutex;
int buffer[BUFF];
void *prod(void* args){
    for(int i=0;i<N;i++){
        sem_wait(&empty);
        sem_wait(&mutex);
        f=(f+1)%BUFF;
        buffer[f]=count;
        count++;
        printf("Produced %i\n",buffer[f]);
        sem_post(&mutex);
        sem_post(&full);
        // sleep(1);
    }
}
void *cons(void* args){
    for(int i=0;i<N;i++){
        sem_wait(&full);
        sem_wait(&mutex);
        r=(r+1)%BUFF;
        printf("Consumer %i\n",buffer[r]);
        sem_post(&mutex);
        sem_post(&empty);
    }
}
int main(){
    pthread_t producer,consumer;
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,BUFF);

    pthread_create(&producer,0,&prod,0);
    pthread_create(&consumer,0,&cons,0);

    pthread_join(consumer,0);
    pthread_join(producer,0);

    sem_destroy(&full);
    sem_destroy(&empty);
    sem_destroy(&mutex);
    
    return 0;
}