# Lesson 4

## Types size
In C types have not a standard size: they depends on the architcture for wich the program is compiled.
We can use the function `sizeOf(x)`, where `x` is a variable, that returns the size of that variable.
It's also possible to include `limits.h` where are defined some constants like `INT_MIN` and `INT_MAX`.

It exists another header file, `stdint.h`, that allow to use types with a defined size:

```c
uint64_t //64 bit unsigned int
int64_t  //64 bit int
size_t
uintptr_t
intptr_t //memory address size (negative, because I might wanto to subtract pointers)
```

## Did you know it about the printf?
printf doesn't write on stdout when you call it, it store the byte in an internal buffer and print them when it encounters a newline `\n` or a ``fflush()` function.
