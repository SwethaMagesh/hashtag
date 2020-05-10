#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/string.h>
#include<asm/uaccess.h>
MODULE_LICENSE(“GPL”);
 int lkm_open(struct inode *pinode, struct file *pfile)
{
printk(KERN_ALERT “device opened”);
return 0;
}
 
ssize_t lkm_read(struct file *pfile,char __user  *buffer,size_t length,loff_t *offset)
{
printk(KERN_ALERT “Device read”);
return 0;
}
 
ssize_t lkm_write(struct file *pfile,const char __user  *buffer,size_t length,loff_t *offset)
{
printk(KERN_ALERT “ Device write”);
return length;
}
 
int lkm_release(struct inode *pinode,struct file *pfile)
{
printk(KERN_ALERT “device closed\n”);
return 0;
}
//structure containing device operation
static struct file_operations fops=
{
.read=lkm_read, //pointer to device read function
.write=lkm_write, //pointer to device write function
.open=lkm_open,   //pointer to device open function
.release=lkm_release, //pointer to device release function
};
 
 
static int hello_init(void)   //init function to be called at the time of insmod
{
int t=register_chrdev(90,”mychr”,&fops);
if(t<0)
printk(KERN_ALERT “device registration failed.”);
else
printk(KERN_ALERT “device registred\n”);
return 0;
}
static void hello_exit(void) //exit function to be called at the time of rmmod
{
unregister_chrdev(90,”mychr”);
printk(KERN_ALERT “exit”);
}
 
 
 
module_init(hello_init);
module_exit(hello_exit);
