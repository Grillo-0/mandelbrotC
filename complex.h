#ifndef __COMPLEX__
#define __COMPLEX__

#include <math.h>

typedef struct{
	double real;
	double imag;
} complex;

complex cSquare(complex z);

complex cSum(complex x, complex y);

complex cMul(complex x, complex y);

double cMod(complex x);

#endif
