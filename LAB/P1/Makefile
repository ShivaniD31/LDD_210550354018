
obj-m := chardev.o
KDIR=/lib/modules/$(shell uname -r)/build/
PWD=$(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o DEV1App DEVapp1.c
	gcc -o DEV2App DEVapp2.c

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -rf DEV1App DEV2App

install:
	make -C $(KDIR) M=$(PWD) modules_install
