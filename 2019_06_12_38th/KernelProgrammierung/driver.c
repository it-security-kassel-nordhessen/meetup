#include <linux/init.h>
#include <linux/module.h>

MODULE_AUTHOR("dieter.kopp@micromata.de");
MODULE_DESCRIPTION("Test driver");
MODULE_LICENSE("GPL");

static int hello_init(void) {
	printk(KERN_ALERT "Test driver: Hello world\n");
	return 0;
}

static void hello_exit(void) {
	printk(KERN_ALERT "Test driver: Bye bye\n");
}

module_init(hello_init);
module_exit(hello_exit);
