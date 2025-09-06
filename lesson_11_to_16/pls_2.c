#include <stdlib.h>
#include <stdio.h>

/* Initialize a prefixed length string with the specified
 * string in 'init' of length 'len'. At the end of that string,
 * we will put the zero byte for defensive programming reasons.
 *
 * The created strings have the following layout:
 *
 * +-+-------------------
 * |L|MyStringGoesHere|0|
 * +-+-------------------
 *
 * Where L is one unsigned byte stating the total length of the string.
 * Thus this strings are binary safe: zero bytes are permitted in the
 * middle if printed with the custom function ps_print
 *
 * WARNING: this function does not check for buffer overflows. */
char *ps_create(char *init, int len) {
	char *s = malloc(1+len+1);
	unsigned char *lenptr = (unsigned char*)s;
	*lenptr = len;
	for (int j = 0; j < len; j++){
		s[j+1] = init[j];
	}
	s[len+1] = 0;
	return s;
}

/* Display string s on the string */
void ps_print(char *s){
	unsigned char *lenptr = (unsigned char*)s;
	for(int j = 0; j < *lenptr; j++) {
		putchar(s[j+1]);
	}
	printf("\n");
}

/* Return the pointer to the null terminated C string embedded
 * inside our PS string 's'. */
char *ps_getc(char *s){
	return s+1;
}

int main(void){
	char *mystr = ps_create("Hello World",11);
	ps_print(mystr);
	ps_print(mystr);
	printf("%s\n", ps_getc(mystr));
	free(mystr);
	return 0;
}
