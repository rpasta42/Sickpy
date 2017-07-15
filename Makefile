fname=sickpy
obj-m += $(fname).o

all: test

test: build
	sudo insmod $(fname).ko; dmesg >/tmp/dmesg; tail /tmp/dmesg; sudo rmmod $(fname).ko


build:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

