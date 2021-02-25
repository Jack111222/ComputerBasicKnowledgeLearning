#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int i = 0;
pthread_mutex_t mutex;
pthread_mutex_t mutex1;

void *func(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex1);
        printf("ifunc=%d\n", i++);
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
}

int main(void)
{
    pthread_t pid;
    pthread_create(&pid, NULL, func, NULL);

    pthread_mutex_init(&mutex, NULL);

    pthread_mutex_init(&mutex1, NULL);

    while(1)
    {
        pthread_mutex_lock(&mutex);
        printf("i=%d\n", i++);
        sleep(1);
        pthread_mutex_unlock(&mutex1);
    }

    return 0;
}
