# Lesson 11

## Notes on last lessons

Nothing new, just an example implementing prefix length strings (the length is set by a prefix and ot by using `\0` character.

# Optimizing Game of life

At some point in the game of life implementation we were using some logic to compute the new grid from the old one. Particularly, in a infinite while loop, we were applying twice the same  logic in that way:

```c
while(1){
	compute_new_state(old_grid,new_grid);
	print_grid(new_grid);
	usleep(100000);
	compute_new_state(nwe_grid,old_grid);
	print_grid(old_grid);
	usleep(100000);
}
```

Now we can rewrite it as follow, being more elegant in and having a cleaner code

```c

char *old = old_grid;
char *new = new_grid;

while(1){
	compute_new_state(old,new);
	print_grid(new);
	usleep(100000);

	char *tmp = old;
	old = new;
	new = tmp;
}
```
