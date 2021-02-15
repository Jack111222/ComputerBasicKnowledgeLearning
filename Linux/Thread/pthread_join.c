#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

static int abc;

void *thread_fun(void *p)
{
	static int abc1;
	while (1)
	{
		sleep(1);
		printf("world %d\n", abc++);
		if (abc > 4)
			pthread_exit((void *)(&abc));
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	static int abc2;
	void *retval;
	int fd;
	int res;
	pthread_t tid;

	res = pthread_create(&tid, NULL, thread_fun, NULL);
	if (res < 0)
	{
		perror ("thread create");
		return -1;
	}

	pthread_join(tid, &retval);
	printf("%d\n", *((int *)retval));

	return 0;
}
