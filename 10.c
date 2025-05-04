#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int counter=0;
pthread_mutex_t mutex;

void *increment(){
    for(int i=0;i<500;i++){
        pthread_mutex_lock(&mutex);
        counter++; //critical section
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void main(){
    pthread_t threads[5];

    pthread_mutex_init(&mutex,NULL);

    for(int i=0;i<5;i++){
        pthread_create(&threads[i],NULL,increment,NULL);
    }

    for(int i=0;i<5;i++){
        pthread_join(threads[i],NULL);
    }
}