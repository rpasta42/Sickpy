
### To check all symbols exported by kernel
`cat /proc/kallsyms`

### Print syscalls made by a C program:
```c
#include <stdio.h>
int main(void)
{ printf("hello"); return 0; }
```

`strace ./hello`



### Device major-minor number:
`ls -l /dev/sda`

Number separated by comma: first number is major, second is minor
Major says which driver is used to access the hardware

Minor number is used by device driver to distinguish between the various hardware it controls.


#### Devices: character devices and block devices

- Block Devices: have a buffer for requests, so they can choose the best order in which to respond to the requests
   - This is important in the case of storage devices, where it's faster to read or write sectors which are close to each other, rather than those which are further apart
   - can only accept input and return output in blocks (whose size can vary according to the device), whereas character devices are allowed to use as many or as few bytes as they like.

- checking which type by first character of `ls -l`
   - if s, then it's block device (sdb)
   - if c, then character device (serial port)

### Memory allocation

```C
void *vmalloc(unsigned long size);
void vfree(void * addr);
```

