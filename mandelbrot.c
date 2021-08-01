#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "complex.h"
#include "ppm.h"

int mandelbrot(complex c);
double map(double input, double input_start, double input_end, double output_start, double output_end);

int main(int argc, char *argv[]){
	if(argc < 3){
		fprintf(stderr,"not enough dimensions");
		exit(-1);
	}
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);

	image *img = initImage("mandelbrot.ppm",width,height,"w");

	int N = 256;
	int N3 = N * N * N;

	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			complex c;
			c.real = map(j,0,width-1,-2,1);
			c.imag = map(i,0,height-1,-1,1);
			printf("created %d lines\r",i);
			int n = mandelbrot(c);
			double t = (double)n/(double)255;
			int rgb[3];
			rgb[0] = (int)(9*(1-t)*t*t*t*255);
			rgb[1] = (int)(15*(1-t)*(1-t)*t*t*255);
			rgb[2] = (int)(8.5*(1-t)*(1-t)*(1-t)*t*255);
			writeNextPixel(img, rgb);
		}
	}
	closeImage(img);
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
	while(i <= 255){
		if(cMod(z) >= 2){
			return i;
		}
		z = cSum(cSquare(z), c);
		i++;
	}
	return 0;
}
