/*
 *  hello−1.c − The simplest kernel module.
 */
#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/init.h>


#define DRIVER_AUTHOR "Kostyantyn Kovalskyy <kostelkow@gmail.com>"
#define DRIVER_DESC   "SICKPY Kernel Interpreter"

int init_module(void)
{
        printk(KERN_INFO "Hello world 1.\n");

        sickpy_init_drive();
        /*
         * A non 0 return means init_module failed; module can't be loaded.
         */
        return 0;
}
void cleanup_module(void)
{
        printk(KERN_INFO "Goodbye world 1.\n");
}




void sickpy_init_drive(void) {

   /* CODE FOR IMPLEMENTING A DRIVE */
   struct file_operations fops = {
      .read = device_read,
      .write = device_write,
      .open = device_open,
      .release = device_release
   };

}
