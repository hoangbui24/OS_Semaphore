//  Name: Bui Duc Hoang
//  MSSV: 20520514

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int x = 0;
pthread_mutex_t mutex;

//  Process A
void* ProcessA()
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        x++;
        if (x == 20) x = 0;
        printf("Process A: x = %d\n", x);
        pthread_mutex_unlock(&mutex);
        //sleep(2);
    }
}

//  Process B
void* ProcessB()
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        x++;
        if (x == 20) x = 0;
        printf("Process B: x = %d\n", x);
        pthread_mutex_unlock(&mutex);
        //sleep(2);
    }
    sleep(2);
}

void main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &ProcessA, NULL);
    pthread_create(&thread2, NULL, &ProcessB, NULL);
    while(1);
}