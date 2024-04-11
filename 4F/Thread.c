#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// thread POSIX
void *stampaCiao(void *par)
{
    printf("%s\n", (char*)par);
    return (void*)0;
}
int main()
{
    pthread_t threadCiao1, threadCiao2, threadCiao3;
    char *msg1 = "ciao 1";
    char *msg2 = "ciao 2";
    char *msg3 = "ciao 3";
    pthread_create(&threadCiao1, NULL, &stampaCiao, msg1);
    pthread_create(&threadCiao2, NULL, &stampaCiao, msg2);
    pthread_create(&threadCiao3, NULL, &stampaCiao, msg3);
    pthread_join(threadCiao1, NULL);
    pthread_join(threadCiao2, NULL);
    pthread_join(threadCiao3, NULL);
}