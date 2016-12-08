# Makefile for the bouncing polygons

# GFLAGS=-g -c -std=c++11 -DDEBUG
GFLAGS=-g -c -std=c++11

fractal: fractal.o 
	g++ fractal.o -lX11 -o fractal.o

fractal.o: fractal.cpp
	g++ ${GFLAGS} fractal.cpp -o fractal.o

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
