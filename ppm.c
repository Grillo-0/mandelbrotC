#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"


image *initImage(char *name, int width, int height, char *mode){
	image *x;
	x = malloc(sizeof(image));
	x->name = name;
	x->width = width;
	x->height = height;
	x->fd = fopen(name,mode);
	
	fprintf(x->fd,"P3\n");
	fprintf(x->fd,"%d %d\n", width, height);
	fprintf(x->fd,"255\n");
	return x;
}

void closeImage(image *x){
	fclose(x->fd);
	free(x);
}

void writeNextPixel(image *x, int  *rgb){
	fprintf(x->fd, "%d\n", rgb[0]);
	fprintf(x->fd, "%d\n", rgb[1]);
	fprintf(x->fd, "%d\n", rgb[2]);
}
