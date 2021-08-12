#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>

MODULE_AUTHOR("Shivani");
MODULE_LICENSE("GPL");

static int int1= 20;
static int int2= 10;
static char* choice= "o";

module_param(int1,int, S_IRUGO);
module_param(int2,int, S_IRUGO);
module_param(choice,charp, S_IRUGO);

static int op_add(int a,int b)
{
	return a+b;
}

static int op_sub(int a,int b)
{
	return a-b;
}
static int op_mul(int a,int b)
{
	return a*b;
}
static int op_div(int a,int b)
{
	return a/b;
}

static int __init funct_init(void)
{
	printk("\n Hello world\n");
	printk("The operation user want is %s\n",choice);
	if(*choice=='a')
	{
	printk(KERN_ALERT "\n SUM is %d\n",op_add(int1,int2));
	}
	else if(*choice=='s')
	{
	printk(KERN_ALERT "\n DIFFERENCE is %d\n",op_sub(int1,int2));
	}
	else if(*choice=='m')
	{
	printk(KERN_ALERT "\n PRODUCT is %d\n",op_mul(int1,int2));
	}
	else if(*choice=='d')
	{
	printk(KERN_ALERT "\n QUOTIENT is %d\n",op_div(int1,int2));
	}
    return 0;
}

static void __exit end_cleanup(void)
{
	printk(KERN_ALERT"\nOkay,bye.");
}

module_init(funct_init);
module_exit(end_cleanup);

