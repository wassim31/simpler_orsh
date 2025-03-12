#include <stdlib.h>
#include <stdio.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int init_module() 
{
    printk(KERN_INFO "Module started\n");
    return 0;
}

void exit_module()
{
    printk(KERN_INFO "Module removed\n");
}

module_init(init_module);
module_exit(exit_module);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("wassim31");
MODULE_DESCRIPTION("a simple trial with kernel");