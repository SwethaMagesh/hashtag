#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
__init int mod1_init(void)
{
 printk(KERN_ALERT "Inside init fun %s",__FUNCTION__);
return 0;
}

void mod1_exit(void)
{

 printk(KERN_ALERT "inside the exit fun %s ", __FUNCTION__);

}
module_init(mod1_init);
module_exit(mod1_exit);
