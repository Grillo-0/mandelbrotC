CFLAGS= -ggdb -Wall -Wextra -pedantic
mandelbrot: mandelbrot.o complex.o ppm.o main.o 
	$(CC) $(CFLAGS) main.o ppm.o complex.o mandelbrot.o -o mandelbrot -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: mandelbrot
	./mandelbrot 500 500

clean:
	rm *.o mandelbrot
