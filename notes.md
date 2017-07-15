
To check all symbols exported by kernel
`cat /proc/kallsyms`


Get syscalls C program calls:
```c
#include <stdio.h>
int main(void)
{ printf("hello"); return 0; }
```

`strace ./hello`
