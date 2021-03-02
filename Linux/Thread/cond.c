#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int i = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *func(void *arg)
{
    while(1)
    {
        printf("6666\n");
        pthread_mutex_lock(&mutex);
        printf("123456\n");
        pthread_cond_wait(&cond, &mutex);

        printf("ifunc = %d\n", i++);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main(void)
{
    pthread_t pid;
    pthread_create(&pid, NULL, func, NULL);

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    while(1)
    {
        pthread_mutex_lock(&mutex);
        printf("i = %d\n", i++);
        if(i == 5)
        {
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    return 0;
}
