all: mandelbrot

mandelbrot: mandelbrot.o complex.o ppm.o
	gcc ppm.o complex.o mandelbrot.o -o mandelbrot

mandelbrot.o: mandelbrot.c
	gcc -c mandelbrot.c -o mandelbrot.o

complex.o: ../complex/complex.c
	gcc -c ../complex/complex.c -o complex.o

ppm.o: ../ppm/ppm.c
	gcc -c ../ppm/ppm.c -o ppm.o

run: mandelbrot
	./mandelbrot

clean:
	rm *.o mandelbrot
