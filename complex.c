#include "complex.h"
#include <math.h>

complex cSquare(complex z){
	complex r;
	r.real = z.real * z.real - z.imag * z.imag;
	r.imag = 2 * z.real * z.imag;
	return r;
}

complex cSum(complex x, complex y){
	complex r;
	r.real = x.real + y.real;
	r.imag = x.imag + y.imag;
	return r;
}

complex cMul(complex x, complex y){
	complex r;
	r.real = x.real * y.real - x.imag * y.imag;
	r.imag = x.real * y.imag + y.real + y.imag;
	return r;
}

double cMod(complex x){
	return sqrt(x.real * x.real + x.imag * x.imag );
}
