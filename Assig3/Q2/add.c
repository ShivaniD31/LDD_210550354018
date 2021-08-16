#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shivani");

static int o_add(int a,int b)
{
	return a+b ;
}

EXPORT_SYMBOL_GPL(o_add);

static int __init h_i(void)
{	
	printk(KERN_ALERT"\nIn the add function of add module.");
	return 0;
}
static void __exit h_e(void)
{
	printk(KERN_ALERT"\nOkay bye from add function add module.");
}
module_init(h_i);
module_exit(h_e);
