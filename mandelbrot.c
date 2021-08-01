#include "mandelbrot.h"

double lerp(double input, double input_start, double input_end, double output_start, double output_end) {
	double slope = 1.0 * (output_end - output_start) / (input_end - input_start);
	return output_start + slope * (input - input_start);
}

void createImage(int width, int height,
				 int xMin, int xMax,
				 int yMin, int yMax,
				 float resolution) {

	image *img = initImage("mandelbrot.ppm",width,height,"w");

	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			complex c;
			c.real = lerp((int)(j*resolution),0,(int)((width-1)*resolution),xMin,xMax);
			c.imag = lerp((int)(i*resolution),0,(int)((height-1)*resolution),yMin,yMax);
			int index = getMandelbrotIndex(c);
            int *rgb = interpolateColors(index);

            writeNextPixel(img, rgb);

			free(rgb);
		}
	}
	closeImage(img);
}

int* interpolateColors(int index){
    int *rgb = malloc(sizeof(int) * 3);
    double t = (double)index/(double)255;
    rgb[0] = (int)(9*(1-t)*t*t*t*255);
    rgb[1] = (int)(15*(1-t)*(1-t)*t*t*255);
    rgb[2] = (int)(8.5*(1-t)*(1-t)*(1-t)*t*255);
    return rgb;
}

int getMandelbrotIndex(complex c){
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
