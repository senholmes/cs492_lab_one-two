#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <asm/uaccess.h>

SYSCALL_DEFINE2(my_syscall, int, x, int, y) {
	printk(KERN_INFO "Pid: %d, my_syscall(%d, %d) = %d\n", current -> pid, x, y, x+y);
	//printk(KERN_INFO "my_syscall(%d, %d) = %d\n", x, y, x+y);
	return x+y;
}

