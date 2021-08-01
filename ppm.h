#ifndef __PPM__
#define __PPM__

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	FILE *fd;
	char *name;
	int width;
	int height;
}image;

image *initImage(char *name, int width, int height, char *mode);

void closeImage(image *x);

void writeNextPixel(image *x, int *rgb);

#endif
