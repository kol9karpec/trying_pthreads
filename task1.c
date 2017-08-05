#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int main(void) {
	pid_t cur_proc_id = fork();

	if(cur_proc_id == -1) {	//fail
		printf("fork() failed!\n");
	} else if (cur_proc_id == 0){ //child
		printf("Child process!\n");
		printf("Running ls...\n");

		
		execlp("ls","ls","-l",NULL);

	} else {
		printf("Parent process!\n");
	}


	return 0;
}
