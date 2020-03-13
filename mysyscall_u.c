#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	long result = syscall(548, 5, 10);

	char * str = "helloworld";
	char buf[128];
	strncpy(buf, str, 128);
	syscall(549, buf);
	long result2 = syscall(549, buf);
	
	int pid = getpid();

	printf("Sen Holmes, process: %d, my_syscall result: %d\n", pid, result);
	printf("Sen Holmes, process: %d, my_syscall2 result: %d\n", pid, result2);
	return 0;

}
