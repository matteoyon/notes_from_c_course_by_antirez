# Lesson 12
## MALLLLLLLLLLOCCCCCCCC

we implement a prefixed length string system (`pls.c`)

Problem with `pls.c`: how to allocate?

In `pls_2.c`, we use malloc function. Given a size, it allocates memory and return a void pointer to that allocation.
Void pointers `(void *)` are pointers that we can assign to any type.

We do also a bit of defensive programming, putting a zero byte at the end of the generated string, so if someone is trying to print it with a printf it should be ok.

## Free the memory with free()
When you want to deallocate memory, use free on the pointer to the portion of memory you'd like to deallocate. Since `pls_2.c` terminates immediatly after using the created string, it's ok because the memory is wiped at the end of the process, but we should do that.


# Lesson 13
## Metadata before pointer

We expand the metadata to 4 byte and we modify the ps implementation, so that when we create the ps string we return a `char *` that can be used in c string functions. However, we should implement a dedicated free function that deallocate not s but s-4.

# Lesson 14
## STRUCTSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS

When I declare a struct with multiple types inside, the memory allocated for the struct makes sure that it's aligned to the biggest type inside the struct itself.

e.g.

struct {
	int num;
	ind den
	unsigned char c;
}

Memory:
+----+----+----+
|num |den |cPPP|
+----+----+----+i

where P is the padding.


This is because I can declare an array of this struct.
Be aware of the optimization:


struct {
	unsigned char a;
	int foo;
	unsigned char b;
	int bar;
	unsigned char c;
	unsigned char d;
}

size: 20
+----+----+----+----+-+---+
|aPPP|foo |bPPP|bar |c|dPP|
+----+----+----+----+-+---+

struct {
	int foo;
	int bar;
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;
}

size: 12
+----+----+-+-+-+-+
|foo |bar |a|b|c|d|
+----+----+-+-+-+-+

How to refer to a component of a struct?

if it's a struct use the dot (.)

`s.foo`
`s.bar`

if it's a pointer use the arrow (->)

`s->foo`
`s->bar`


