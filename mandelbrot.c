#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "../complex/complex.h"
#include "../ppm/ppm.h"

int mandelbrot(complex c);
double map(double input, double input_start, double input_end, double output_start, double output_end);

int main(int argc, char *argv[]){
	if(argc < 3){
		fprintf(stderr,"not enough dimensions");
		exit(-1);
	}
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int **values = malloc(sizeof(int *) * height);

	for(int i=0; i<height; i++){
		values[i] = malloc(sizeof(int) * width);
		for(int j=0; j<width; j++){
			complex c;
			c.real = map(j,0,width-1,-2,1);
			c.imag = map(i,0,height-1,-1,1);
			printf("%d %d\n",i,j);
			values[i][j] = mandelbrot(c);
		}
	}
	printf("teriminado\n");
	writeP2("mandelbrot.ppm",width,height,255, values);
}

double map(double input, double input_start, double input_end, double output_start, double output_end){
	double slope = 1.0 * (output_end - output_start) / (input_end - input_start);
	return output_start + slope * (input - input_start);
}
int mandelbrot(complex c){
	complex z;
	z.real = 0.0;
	z.imag = 0.0;

	int i =0;
	while(i < 255){
		z = cSum(cSquare(z), c);
		if(cMod(z) >= 2){
			return i;
		}
		i++;
	}
	return 0;
}
