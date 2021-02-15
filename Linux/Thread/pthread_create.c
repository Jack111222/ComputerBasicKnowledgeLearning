#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int i=100;
void *func(void *arg)
{
	int i=0;
	while(1)
	{
		//pthread_exit(arg);
		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
		printf("i=%d\n",i++);
		sleep(1);
	}
}
int main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,func,NULL);
	//pthread_detach(tid);

	int j=0;
	while(1)
	{
		if(j==7)
			pthread_cancel(tid);
		printf("j=%d\n",j++);
		sleep(1);
	}
}
