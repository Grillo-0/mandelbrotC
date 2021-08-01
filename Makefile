all: mandelbrot

mandelbrot: mandelbrot.o complex.o ppm.o
	gcc ppm.o complex.o mandelbrot.o -o mandelbrot -lm

mandelbrot.o: mandelbrot.c
	gcc -c mandelbrot.c -o mandelbrot.o

complex.o: complex.c
	gcc -c complex.c -o complex.o

ppm.o: ppm.c
	gcc -c ppm.c -o ppm.o

run: mandelbrot
	./mandelbrot

clean:
	rm *.o mandelbrot
