#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/* Initialize a prefixed length string with the specified
 * string in 'init' of length 'len'. At the end of that string,
 * we will put the zero byte for defensive programming reasons.
 *
 * The created strings have the following layout:
 *
 * +-+-------------------
 * |LLLL|MyStringGoesHere|0|
 * +-+-------------------
 *
 * Where L is one unsigned byte stating the total length of the string.
 * Thus this strings are binary safe: zero bytes are permitted in the
 * middle if printed with the custom function ps_print
 *
 * WARNING: this function does not check for buffer overflows. */
char *ps_create(char *init, int len) {
	char *s = malloc(4+len+1);
	uint32_t *lenptr = (uint32_t*)s;
	*lenptr = len;

	s += 4;
	for (int j = 0; j < len; j++){
		s[j] = init[j]; // We should use memcpy()
	}
	s[len] = 0;
	return s;
}

/* Display string s on the string */
void ps_print(char *s){
	uint32_t *lenptr = (uint32_t*)(s-4);
	for(int j = 0; j < *lenptr; j++) {
		putchar(s[j]);
	}
	printf("\n");
}

/* Free a previously created PS String */
void ps_free(char *s){
	free(s-4);
}


/* Returns ps_string length in O(1) time */
uint32_t ps_len(char *s){
	uint32_t *lenptr = (uint32_t*)(s-4);
	return *lenptr;
}

int main(void){
	char *mystr = ps_create("Hello World",11);
	ps_print(mystr);
	ps_print(mystr);
	printf("%s %d\n", mystr, (int)ps_len(mystr));
	ps_free(mystr);
	return 0;
}
