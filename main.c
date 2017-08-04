#include <stdio.h>
#include <pthread.h>

pthread_t threads_arr[3];

void* thread(void * arg) {
	printf("Thread #%d\n",*(int*)(arg));
	return NULL;
}

int main(void) {
	unsigned int i = 0;


	for(i = 0;i<3;i++) {
		pthread_create(&threads_arr[i],NULL,&thread,(void*)(&i));
		printf("Thread %u created!\n",i);
	}

	for(i = 0;i<3;i++) {
		pthread_join(threads_arr[i],NULL);
		printf("Thread %u joined!\n",i);
	}

	return 0;
}
