//  Ho va ten: Bui Duc Hoang
//  MSSV: 20520514
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem15, sem16, sem23, sem24, sem35, sem46, sem57, sem67;
int x1 = 1;
int x2 = 2;
int x3 = 3;
int x4 = 4;
int x5 = 5;
int x6 = 6;
int w, v, x, y, z, ans = 0;

void* ProcessA()
{
    w = x1 * x2;
    printf("w = %d\n", w);
    sem_post(&sem15);
    sem_post(&sem16);
    sleep(1);
}

void* ProcessB()
{
    v = x3 * x4;
    printf("v = %d\n", v);
    sem_post(&sem23);
    sem_post(&sem24);
    sleep(1);
}

void* ProcessC()
{
    sem_wait(&sem23);
    printf("y = %d\n", y);
    y = v * x5;
    sem_post(&sem35);
    sleep(1);
}

void* ProcessD()
{
    sem_wait(&sem24);
    printf("z = %d\n", z);
    z = v * x6;
    sem_post(&sem46);
    sleep(1);
}

void* ProcessE()
{
    sem_wait(&sem15);
    sem_wait(&sem35);
    y = w * y;
    printf("y = %d\n", y);
    sem_post(&sem57);
    sleep(1);
}

void* ProcessF()
{
    sem_wait(&sem16);
    sem_wait(&sem46);
    z = w * z;
    printf("z = %d\n", z);
    sem_post(&sem67);
    sleep(1);
}

void* ProcessG()
{
    sem_wait(&sem57);
    sem_wait(&sem67);
    ans = y + z;
    printf("ans = %d\n", ans);
    sleep(1);
}

void main()
{
    sem_init(&sem15, 0, 1);
    sem_init(&sem16, 0, 0);
    sem_init(&sem23, 0, 0);
    sem_init(&sem24, 0, 0);
    sem_init(&sem35, 0, 0);
    sem_init(&sem46, 0, 0);
    sem_init(&sem57, 0, 0);
    sem_init(&sem67, 0, 0);
    pthread_t t1, t2, t3, t4, t5, t6, t7;
    pthread_create(&t1, NULL, &ProcessA, NULL);
    pthread_create(&t2, NULL, &ProcessB, NULL);
    pthread_create(&t3, NULL, &ProcessC, NULL);
    pthread_create(&t4, NULL, &ProcessD, NULL);
    pthread_create(&t5, NULL, &ProcessE, NULL);
    pthread_create(&t6, NULL, &ProcessF, NULL);
    pthread_create(&t7, NULL, &ProcessG, NULL);
    while(1);
}

