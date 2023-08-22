#
# Vecow's GPIO driver
# 

ccflags-y += -Wno-unused-variable -I$(srctree)/drivers/media/platform/tegra/ -I$(srctree)/../nvidia/include/
obj-m += vecow_gpio.o
vecow_gpio-objs := gpio.o 

all:
	make -C $(KERNEL_PATH) M=$(PWD) modules
clean:
	make -C $(KERNEL_PATH) M=$(PWD) clean
