
#sickpy
fname=chardev
obj-m += $(fname).o

msg=dmesg >/tmp/dmesg; tail /tmp/dmesg

all: test

test: build
	make load; make unload

load:
	sudo insmod $(fname).ko; $(msg)

unload:
	sudo rmmod $(fname).ko; $(msg)


build:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

