#include <stdio.h>

/* Initialize a prefixed length string with the specified
 * string in 'init' of length 'len'
 *
 */
void ps_init(char *s, char *init, int len) {
	unsigned char *lenptr = (unsigned char*)s;
	*lenptr = len;

	for (int j = 0; j < len; j++){
		s[j+1] = init[j];
	}
}

/* Display string s on the string */
void ps_print(char *s){
	unsigned char *lenptr = (unsigned char*)s;
	for(int j = 0; j < *lenptr; j++) {
		putchar(s[j+1]);
	}
	printf("\n");
}

int main(void){
	char buf[256];
	ps_init(buf,"Hello World",11);
	ps_print(buf);
	ps_print(buf);
	return 0;
}
