#include "mandelbrot.h"

int main(int argc, char *argv[]){
	if(argc < 3){
		fprintf(stderr,"not enough dimensions");
		exit(-1);
	}
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
    
    createImage(width, height, -2,2,-2,2,0.2f);
}
