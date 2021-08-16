#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>
#include "kern_add.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shivani");

static int int1=45;
static int int2=55;

module_param(int1,int, S_IRUGO);
module_param(int2,int, S_IRUGO);

static int __init avg_init(void)
{
	int avg;
	printk(KERN_ALERT"\nIn the average init to find average of module param");
	avg=(o_add(int1,int2))/2;
	printk(KERN_ALERT"\nThe average is %d.\n",avg);
	return 0;
}

static void __exit avg_exit(void)
{
	printk(KERN_ALERT"\nOkay bye from avgerage exit.");
}

module_init(avg_init);
module_exit(avg_exit);
