/*
 * Vecow's GPIO driver for reset GPIO pin.
 */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/delay.h>

#define GPIO_PIN 317

static int __init gpio_init(void)
{
    int ret;

    printk(KERN_INFO "Vecow's GPIO driver loaded.\n");

    ret = gpio_request(GPIO_PIN, "GPIO Driver");
    if (ret) {
        printk(KERN_ERR "Failed to request GPIO pin %d !!!\n", GPIO_PIN);
        return ret;
    }

    printk(KERN_INFO "Reset GPIO pin %d\n", GPIO_PIN);
    gpio_direction_output(GPIO_PIN, 1);
    usleep_range(1000000, 1000001);
    gpio_direction_output(GPIO_PIN, 0);
    usleep_range(1000000, 1000001);
    gpio_direction_output(GPIO_PIN, 1);

    return 0;
}

static void __exit gpio_exit(void)
{
    printk(KERN_INFO "Vecow's GPIO driver unloaded.\n");

    gpio_free(GPIO_PIN);
}

module_init(gpio_init);
module_exit(gpio_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Vecow Software");
MODULE_DESCRIPTION("Vecow's GPIO driver for reset.");
