#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>
#include<linux/wait.h>
#include<linux/semaphore.h>
#define NAME Mydevice

int NAME_open(struct inode *inode,struct file *filp);
int NAME_release(struct inode *inode,struct file *filp);
ssize_t Read_Dev1(struct file *filp,const char __user *Ubuff,ssize_t count,loff_t *offp);
ssize_t Read_Dev2(struct file *filp,const char __user *Ubuff,ssize_t count,loff_t *offp);
ssize_t Write_Dev1(struct file *filp,const char __user *Ubuff,ssize_t count,loff_t *offp);
ssize_t Write_Dev2(struct file *filp,const char __user *Ubuff,ssize_t count,loff_t *offp);
struct file_operations fops_dev1 =
{
	.owner = THIS_MODULE,
	.open = NAME_open,
	.release = NAME_release,
	.read = Read_Dev1,
	.write = Write_Dev1,
};
struct file_operations fops_dev2 =
{
	.owner = THIS_MODULE,
	.open = NAME_open,
	.release = NAME_release,
	.read = Read_Dev2,
	.write = Write_Dev2,
};
struct cdev *dev1;
struct cdev *dev2;
int result1,result2;
static DECLARE_WAIT_QUEUE_HEAD(wq);
static int __init chardev_init(void)
{
	int MAJOR,MINOR;
	dev_t Dev1, Dev2;
	Dev1 = MKDEV(256,0);
	Dev2 = MKDEV(256,1);
	result1 = register_chrdev_region(Dev1,1,"Device1");
	result2 = register_chrdev_region(Dev2,1,"Device2");
	if(result1<0||result2<0)
	{
		printk("\nError in allocation region");
		return (-1);
	}
	dev1 = cdev_alloc();
	dev1->ops = &fops_dev1;
	dev2 = cdev_alloc();
	dev2->ops = $fops_dev2;
	result1 = cdev_add(dev1,Dev1,1);
	result2 = cdev_add(dev2,Dev2,1);
	if(result1<0||result2<0)
	{
		printk("\nError");
		unregister_chrdev_region(Mydev,2);
		return(-1);
	}
	return 0;
}
void __exit chardev_exit(void)
{
	cdev_del(dev1);
	cdev_del(dev2);
	unregister_chrdev_region(Dev1,1);
	unregister_chrdev_region(Dev2,1);
	printk("\nUnregistered");
}
int NAME_open(struct inode *inode,struct file *filp)
{
	printk("\nThis is an open call");
	return 0;
}
int NAME_release(struct inode *inode,struct file *filp)
{
	printk("\nThis is a close call");
	return 0;
}
char Kbuff[50];
char obuff[50];
int flag1,flag2;
ssize_t Read_Dev1(struct file *filp, const char __user *Ubuff,ssize_t count,loff_t *offp)
{
	ssize_t ret;
	unsigned long remaining;
	wait_event(wq,flag1==1||flag2==1);
	printk("\n Read command called by device 1");
	remaining = copy_to _user((char*)Ubuff,&obuff,count);
	wake_up(&wq);
	if (remaining == 0)
	{
		printk("\n Data has been succesfully copied");
		return count;
	}
	else if (remeining>0)
	{
		printk("\n %d data is still remaining to be read",count-remaining);
		return count-remaining;
	}
	else
	{
		printk("\nError Reading data");
		ret = -EFAULT;
		return ret;
	}
	return 0;

}
ssize_t Read_Dev2(struct file *filp, const char __user *Ubuff,ssize_t count,loff_t *offp)
{
	ssize_t ret;
	unsigned long remaining;
	wait_event(wq,flag2==1||flag1==1);
	printk("\n Read command called by device 2");
	remaining= copy_to_user((char*)Ubuff,&obuff,count);
	wake_up(&wq);
	if(remaining == 0)
	{
		printk("\n Data has been successfully copied");
		return count;
	}
	else if(remaining>0)
	{
		printk("\n %d data is still remaining to be read",count-remaining);
		return count-remaining;
	}
	else
	{
		printk("\nError Reading data");
		ret = -EFAULT;
		return ret;
	}
	return 0;
}
ssize_t Write_Dev1(struct file *filp,const char __user *Ubuff,ssize_t count,loff_t *offp)
{
	unsigned long remaining;
	ssize_t ret;
	wait_event(wq,flag2==1)
	printk("\nWriting Data device 1");
	flag1=0;
	remaining=copy_from_user((char *)Kbuff,(char*)Ubuff,count);
	if(remaining == 0)
	{
		printk("Data successfully read from user on dev 1");
		obuff=Kbuff;
		flag1=1;
		return count;
	}
	else if(remaining>0)
	{
		printk("\nData partially read from user %s",Kbuff);
		return count-remaining;
	}
	else
	{
		printk("Error Writing data");
		ret = -EFAULT;
		return ret;
	}
	return 0;

}
ssize_t Write_Dev2(struct file *filp,const char __user *Ubuff,ssize_t count,loff_t *offp)
{
	unsigned long remaining;
	ssize_t ret;
	wait_event(wq,flag1==1);
	printk(("\nWriting Data device 2");
	flag2=0;
	remaining=copy_from_user((char*)Kbuff,(cahr*)Ubuff,count);
	if(remaining == 0)
	{
		printk("Data successfully read from user on dev 2");
		obuff=Kbuff;
		flag2=1;
		return count;
	}
	else if (remaining>0)
	{
		printk("\n Data partially read from user %s",Kbuff);
		return count-remaining;
	}
	else 
	{
		printk("Error writing data");
		ret = -EFAULT;
		return ret;
	}
	retrun 0;

}
module_init(chardev_init);
module_exit(chardev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shivani");

