#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 1000

int numeri[MAX];
void *controlloMeta(void *arg)
{
    int *range = (int *)arg;
    for (int i = *range; i< *(range + 1); i++)
    {
        //printf("%d\n", numeri[i]);//test
        if (numeri[i] == 20)
        {
            printf("il numero e' presente nella posizione: %d\n", i);
        }
    }
}

int main()
{
    pthread_t t1, t2, t3, t4;
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        numeri[i] = rand() % 501;
    }
    int unQuarto = MAX / 4;
    int rangeT1[2] = {0, unQuarto};
    int rangeT2[2] = {unQuarto, unQuarto * 2};
    int rangeT3[2] = {unQuarto * 2, unQuarto * 3};
    int rangeT4[2] = {unQuarto * 3, MAX};
    pthread_create(&t1, NULL, *controlloMeta, (void *)&rangeT1);
    pthread_create(&t2, NULL, *controlloMeta, (void *)&rangeT2);
    pthread_create(&t3, NULL, *controlloMeta, (void *)&rangeT3);
    pthread_create(&t4, NULL, *controlloMeta, (void *)&rangeT4);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_exit(&t1);
    pthread_exit(&t2);
    pthread_exit(&t3);
    pthread_exit(&t4);
}