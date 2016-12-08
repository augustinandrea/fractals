# Makefile for the bouncing polygons

# GFLAGS=-g -c -std=c++11 -DDEBUG
GFLAGS=-g -c -std=c++11

fractal: fractal.o polygon.o
	g++ fractal.o polygon.o gfx.o -lX11 -o fractal

fractal.o: fractal.cpp polygon.h
	g++ ${GFLAGS} fractal.cpp -o fractal.o

polygon.o: polygon.cpp polygon.h
	g++ ${GFLAGS} polygon.cpp -o polygon.o

clea:
	rm -f fractal.o *~ fractal

commit:
	git commit -m "Update" *.h *.cpp Makefile

pull:
	-make commit
	git pull https://github.com/augustinandrea/fractals

push:
	make pull
	git push
