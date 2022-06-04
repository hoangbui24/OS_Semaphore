//  Name: Bui Duc Hoang
//  MSSV: 20520514

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;
int sells, products = 0;

//  Process A, which is seller alike
void* ProcessA()
{
    while(1)
    {
        sem_wait(&sem);
        sells++;
        printf("Sells = %d\n", sells);
        sleep(2);
    }
}

//  Process B, which is producer alike
void* ProcessB()
{
    while(1)
    {
        if (products <= sells + 14 + 10)
        {
            products++;
            printf("Products = %d\n", products);
            sem_post(&sem);
            sleep(1);
        }
    }
}

void main()
{
    sem_init(&sem, 0, 0);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &ProcessA, NULL);
    pthread_create(&thread2, NULL, &ProcessB, NULL);
    while(1);
}