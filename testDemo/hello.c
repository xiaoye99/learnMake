#include <stdio.h>
#include <pthread.h>


void *work(void *args)
{
    printf("pthread!\n");
}

void hello()
{
    pthread_t tid;
    pthread_create(&tid, NULL, work, NULL);

    printf("ni hao!");
}