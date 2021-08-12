#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_AUTHOR("SHIVANI");
MODULE_LICENSE("GPL");

static int intpar = 24;
static int intvar = 67;

module_param(intpar, int ,S_IRUGO);
module_param(intvar, int ,S_IRUGO);

static int __init param_init(void)
{
	printk(KERN_ALERT"\nThis is the init function");
	printk(KERN_ALERT"\n The value of integer 1 passed as parameter is %d\n",intpar);
	printk(KERN_ALERT"\n The value of integer 2 passed as parameter is %d\n",intvar);
	return 0; //Lets you know about the initialisation of module 
}

static void __exit param_exit(void)
{
	printk(KERN_ALERT"\nGoodbye");
}

module_init(param_init);
module_exit(param_exit);


