#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


#define wcount 10
#define rcount 50
sem_t mutex,wrt;
int reader=0;
void* writer(void* arg){
    for(int i=0;i<wcount;i++){
        sem_wait(&wrt);
        printf("%i writer is writing\n",i);
        sem_post(&wrt);
        sleep(3);
    }
}
void* readers(void* arg){
    for(int i=0;i<rcount;i++){
        sem_wait(&mutex);
        reader++;
        if(reader==1) sem_wait(&wrt);
        sem_post(&mutex);
        printf("%i is reading \n",i);
        sem_wait(&mutex);
        reader--;
        if(reader==0) sem_post(&wrt);
        sem_post(&mutex);
        sleep(1);
    }
}
int main(){
    pthread_t w,r;
    
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    
    pthread_create(&w,0,&writer,0); 
    pthread_create(&r,0,&readers,0); 

    pthread_join(w,0);
    pthread_join(r,0);
    
    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}