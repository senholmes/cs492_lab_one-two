
#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <asm/uaccess.h>

//#define MAX_STRING_LEN 128

SYSCALL_DEFINE1(my_syscall2, char*, arg) {
	char buffer[128];
	int result = 0;
	copy_from_user(buffer, arg, 128);
	
	size_t len = strlen(buffer);
	//char dub[len];
	int i=0;

	if(len > 128) {
		result = -1;
	}
	while (i<len) {
		if (buffer[i]== 'o') {
			buffer[i] = '0';
			result++;
			i++;
		}
		else {
			//dub[i] = buffer[i];
			i++;
		}

	}
	
	//printk(KERN_INFO "Result: %c", buffer);
	copy_to_user(arg, buffer, 128);
	printk(KERN_INFO "Pid: %d, my_syscall2(%s) -> %s\n", current->pid, arg, buffer);
	return result;
}
