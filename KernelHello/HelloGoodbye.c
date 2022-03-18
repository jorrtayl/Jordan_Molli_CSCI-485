#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Molli Bishop and Jordan Taylor");
MODULE_DESCRIPTION("A Hello and Goodbye in the Kernel");
MODULE_VERSION("0.01");

static int hello(void) {
 printk(KERN_INFO "Hello World!\n");
 return 0;
}
static void bye(void) {
 printk(KERN_INFO "Goodbye World!\n");
}
module_init(hello);
module_exit(bye);
