# Lesson 1

Compile with cc: `cc hello_world.c`

Informations about file: `file a.out`

Hexdump improved: `hexdump -C a.out`

Intermediate compilation to assembly: `cc -S hello_world.c`

**Compilation with active optimization:** `cc -O2 hello_world.c`

## The C manual:

`man 3 <command>`

## What happens in the hello world program?

```c
#include <stdio.h>

int main(void){
	printf("Hello World\n");
	return 0;
}
```

`#include <stdio.h>` the preprocessor take the file stdio.h and include all his content replacing `#include <stdio.h>` (you can do the same thing with c files, but you should use "" instead of <>)


# Prototyping functions:

you can add a function prototype in a file to get the compiler knows the signature of the function (name, parameters and return type):

```c
int printf(const char * restrict format, ...);

int main(void) {
	printf("Hello World\n");
	return 0;
}
```
