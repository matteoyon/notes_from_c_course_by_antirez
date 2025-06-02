# Lesson 2

(skipping notes for printf and functions returning type)

## Local variables:

local variables lifecycle ends within the scope in which they are defined. If I have a function

```c
int sum(int x, int y){
	int a = x;
	int b = y;

	return a+b;
}
```

all the times this function is called, x, y, a and b are instanciated again. This is crucial to understand if it we plan to export a pointer to their memory address outside the function.

## Main function
The main function is the entry point of our program. It must return an int, accept no parameters (void) and being called "main".
The int value that return ususally gives us a suggestion if the program ended succesfull (return 0) or not (any other thing != 0). This can be useful also in shell scripts, since when we execute programs using `&&` to concatenate them, it will use the lazy evaluation: in the case a program fails (return != 0), the script won't execute other programs:

```bash
# my_succesfull_program returns 0

~ ./my_succesfull_program && ls
SUCCESS!
home	dev	bin	tmp
~

# my_failing_program returns 1
~./my_failing_program && ls
BAD BAD NOT GOOD :(
~
```
We can show the return value explicitely echoing the `?` variable:

```bash
~ ./my_program; echo $?
SUCCESS!
0
~
```

