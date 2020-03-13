#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>

long my_sys(int a, int b) {
	return syscall(548, a, b);
}

long my_sys2(char *arg) {
	return syscall(549, arg);
}

int main(int argc, char *argv[]) {
	long int result = my_sys(5,7);
	int pid = getpid();

	printf("Sen Holmes, process: %d, my_syscall returned: %d\n", pid, result);
	long int result2 = my_sys2("helloworld");
	printf("Sen Holmes, process: %d, my_syscall2 returned: %d\n", pid, result2);
	return 0;
}
