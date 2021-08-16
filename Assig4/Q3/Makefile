obj-m := Chardriver.o
KDIR=/lib/modules/$(shell uname -r)/build/
PWD=$(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o Appplication Application.c

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm - rf Application

install:
	make -C $(KDIR) M=$(PWD) modules_install
