#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

int numeri[10] = {3, 8, 1, 6, 43, 6, 8, 9, 10, 21};
void *controlloMeta1(void *arg)
{
    for (int i = 0; i < (int)arg; i++)
    {
        if (numeri[i] == 8)
        {
            printf("nella prima matà dei numeri il numero 8 è presente nella posizione %d\n", i);
        }
        else if (i == 5 && numeri[i] != 8)
        {
            printf("il numero 8 non è presente nella prima metà dei numeri");
        }
    }
}
void *controlloMeta2(void *arg)
{
    for (int i = 5; i < (int)arg; i++)
    {
        if (numeri[i] == 8)
        {
            printf("nella seconda matà dei numeri il numero 8 è presente nella posizione %d\n", i);
        }
        else if (i == 5 && numeri[i] != 8)
        {
            printf("il numero 8 non è presente nella seconda metà dei numeri");
        }
    }
}
int main()
{
    pthread_t tMeta1, tMeta2;

    pthread_create(&tMeta1, NULL, *controlloMeta1, (int *)5);
    pthread_create(&tMeta2, NULL, *controlloMeta2, (int *)10);
    pthread_join(tMeta1, NULL);
    pthread_join(tMeta2, NULL);
}