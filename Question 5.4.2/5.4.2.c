//  Name: Bui Duc Hoang
//  MSSV: 20520514

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem1, sem2;
int n;
int i = 0;
static int count = 0;
int a[10000];

void* ProcessA()
{
    while(1)
    {
        if (count < n)
        {
            a[i++] = rand() % (n - 1);
            count++;
            printf("\n[IN] Number of elements in array a: %2d", count);
        }
        int sleep_time = rand() % 2 + 1;
        sleep(sleep_time);
        sem_post(&sem1);
    }
}

void* ProcessB()
{
    int j, m;
    while(1)
    {
        sem_wait(&sem1);
        if (count == 0)
        {
            printf("\n[OUT] Nothing left in array a");
        }
        else
        {
            count--;
            m = a[0];
            for (j = 0; j < count; j++)
                a[j] = a[j + 1];
            printf("\n[OUT] Number of elements in array a: %2d", count);
        }
        int sleep_time = rand() % 2 + 1;
        sleep(sleep_time);
    }
}

void main()
{
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);
    printf("Enter your n: ");
    scanf("%d", &n);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &ProcessA, NULL);
    pthread_create(&thread2, NULL, &ProcessB, NULL);
    while(1);
}