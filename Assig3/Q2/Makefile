
obj-m := avg.o add.o
KDIR=/lib/modules/$(shell uname -r)/build/
PWD=$(shell pwd)

all: 
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -rf /lib/modules/$(shell uname -r)/extra/

default:
	make -C $(KDIR) M=$(PWD) modules_install
depmod -a:


