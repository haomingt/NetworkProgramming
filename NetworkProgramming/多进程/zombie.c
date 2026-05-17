#include<stdio.h>
#include<unistd.h>

int main() {
	pid_t pid = fork();
	if (pid == 0) {
		printf("Hi,I am a child process\n");
	}
	else {
		printf("Child Process ID:%d \n", pid);
		sleep(180);
	}
	if (pid == 0) {
		puts("End child process\n");
	}
	else {
		puts("End parent process\n");
	}
	return 0;
}