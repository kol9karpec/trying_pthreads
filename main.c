#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#define THREADS_COUNT 3

static volatile int id = 0;
static pthread_mutex_t id_lock;
static volatile unsigned char is_continue = 1;

static pthread_t threads[THREADS_COUNT] = {0};

int getid(void) {
	int ret_value = 0;
	pthread_mutex_lock(&id_lock);
	ret_value = id++;
	pthread_mutex_unlock(&id_lock);

	return ret_value;
}

void* getid_loop(void* arg) {
	while(is_continue) {
		printf("id: %d\n",getid());
		sleep(1);
	}

	return NULL;
}

void sigint_handler(int arg) {
	unsigned int i = 0;

	printf("SIGINT handled!\n");

	is_continue = 0;

	for(i = 0;i < THREADS_COUNT;i++) {
		pthread_join(threads[i],NULL);
	}

	exit(0);
}

int main(int argc, char * const argv[]) {
	unsigned int i = 0;

	signal(SIGINT,sigint_handler);

	for(i = 0;i < THREADS_COUNT;i++) {
		pthread_create(&threads[i],NULL,getid_loop,NULL);
	}
	while(1) {}

	return 0;
}
