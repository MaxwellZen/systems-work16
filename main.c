#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>

int main() {
	printf("About to fork:\n");
	int f = fork();
	if (f) f = fork();
	if (!f) {
		printf("Child pid: %d\n", getpid());
		srand(getpid());
		int w = rand()%4 + 2;
		sleep(w);
		printf("Process %d finished sleeping for %d seconds\n", getpid(), w);
		return w;
	} else {
		int w;
		f = wait(&w);
		printf("Completed child with pid %d was asleep for %d seconds\n", f, WEXITSTATUS(w));
		printf("Parent done\n");
		return 0;
	}
}
