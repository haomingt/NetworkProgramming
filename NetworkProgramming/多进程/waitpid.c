#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	int status;
	pid_t pid = fork();
	if (pid == 0) {
		sleep(20);
		return 24;
	}
	else {
		while (waitpid(-1, &status, WNOHANG) == 0) {
			sleep(8);
			puts("sleep 8sec.");
		}
		if (WIFEXITED(status)) {
			printf("Child send %d \n", WEXITSTATUS(status));
		}
	}
	return 0;
}