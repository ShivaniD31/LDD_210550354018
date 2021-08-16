#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>

#define Name MyDevice


int NAME_open(struct inode *inode,struct file *filp);
int NAME_release(struct inode *inode,struct file *filp);

struct file_operations fops=
{	.owner = THIS_MODULE,
	.open = NAME_open,
	.release = NAME_release,
};

struct cdev *my_cdev;

static int __init cd_init(void)
{
	int result;
	int MAJOR,MINOR;
	dev_t Mydev;
	Mydev = MKDEV(256,0);
	MAJOR = MAJOR(Mydev);
	MINOR = MINOR(Mydev);
	printk(KERN_ALERT"\n The major number is %d and minor number is %d ",MAJOR,MINOR);
	result = register_chrdev_region(Mydev,1,"MyCharDevice");
	if(result<0)
	{
		printk("\n Error");
		return(-1);
	}
	my_cdev= cdev_alloc();
	my_cdev->ops=&fops;
	result= cdev_add(my_cdev,Mydev,1);
	if(result<0)
	{
		printk("\n Eror obtaining region");
		unregister_chrdev_region(Mydev,1);
		return(-1);
	}
	return 0;
}
void __exit cd_exit(void)
{
	dev_t Mydev;
	int MAJOR,MINOR;
	Mydev=MKDEV(255,0);
	MAJOR=MAJOR(Mydev);
	MINOR=MINOR(Mydev);
	printk("\n The Major number is %d and Minor number is %d",MAJOR,MINOR);
	unregister_chrdev_region(Mydev,1);
	cdev_del(my_cdev);
	printk("\nUnregistered");
	return ;
}
int NAME_open(struct inode *inode,struct file *filp)
	{
		printk(KERN_ALERT"\nThis is an open call");
		return 0;
	}
int NAME_release(struct inode *inode,struct file *filp)
{
	printk("\nTHis is a close call");
	return 0;
}
module_init(cd_init);
module_exit(cd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shivani");
