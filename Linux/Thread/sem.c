#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>

char buf[200] = {0};
sem_t sem;
unsigned int flag = 0;

//child pthread program, count the number of characters in buf and print
void *func(void *arg)
{
    sem_wait(&sem);
    while(flag == 0)
    {
        printf("%d characters are entered this time\n", (int)strlen(buf));
        memset(buf, 0, sizeof(buf));
        sem_wait(&sem);
    }

    pthread_exit(NULL);
}

int main(void)
{
    int ret;
    pthread_t th;

    sem_init(&sem, 0, 0);

    ret = pthread_create(&th, NULL, func, NULL);
    if(ret != 0)
    {
        printf("pthread_create error.\n");
        exit(1);
    }

    printf("enter a string that ends with a carriage return\n");
    while(scanf("%s", buf))
    {
        if(!strncmp(buf, "end", 3))
        {
            printf("program end\n");
            flag = 1;
            sem_post(&sem);
            break;
        }

        sem_post(&sem);
    }

    printf("wait to recycle child thread\n");
    ret = pthread_join(th, NULL);
    if(ret != 0)
    {
        printf("pthread_join error\n");
    }
    printf("recycle child thread successfully\n");

    sem_destroy(&sem);

     return 0;
}
