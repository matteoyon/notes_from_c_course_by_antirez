#include <stdio.h>
#include <stdlib.h>

/* Internal layout
 *
 * +----+----+
 * c|num |den |
 * +----+----+
 */
struct fract {
	unsigned char color;
	int num;
	int den;
};

/* Create a new fraction, setting num and den as the numerator
 * and denominator of the fraction.
 * The function return NULL on out of memory, otherwise the
 * fraction object is returned. */
struct fract *set_fraction(int num, int den){
	struct fract *f = malloc(sizeof(*f));
	if (f == NULL) return NULL;

	f->num = num;
	f->den = den;
	return f;
}

void simplify_fraction(struct fract *f){
	for (int d = 2; d <= f->num && d <= f->den; d++) {
		while (f->num % d == 0 && f->den % d == 0) {
			f->num /= d;
			f->den /= d;
		}
	}
}

void print_fraction(struct fract *f){
	printf("%d/%d\n", f->num, f->den);
}

int main(void) {
	/* |1111|2222|
	 * f[0] := |1111|
	 * f[1] := |2222|
	 */
	
	struct fract *a = set_fraction(10,20);
	simplify_fraction(a);
	print_fraction(a);
	return 0;

	/*
	int *f = set_fraction(10,20);
	int *g = set_fraction(3,4);
	simplify_fraction(f);
	print_fraction(f);
	return 0;
	*/
}
