#include "complex.h"
#include "ppm.h"

int getMandelbrotIndex(complex c);
void createImage(int width, int height,
				 int xMin, int xMax,
				 int yMin, int yMax,
				 float resolution);
double map(double input, double input_start, double input_end, double output_start, double output_end);
int* interpolateColors(int index);
