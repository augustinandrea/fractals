// candidate for overall structure of the fractals program
#include "gfx.h"
#include <cmath>

// function prototypes
void drawSierpinski(int,int,int,int,int,int);
void drawShrinkingSquares();
void drawSpiralSquares();
void drawCircularSpace();
void drawSnowflake();
void drawTree();
void drawFern();
void drawSpirals();


int main() {

  // variables
  wd = 500;
  ht = 400;

  gfx_open(wd, ht, "Fractal 1");

  while (gfx_wait() != 'q') {
    c = gfx_wait();
    gfx_clear();

    switch (c) {
      case '1':  // Sierpinski Triangle   
       // (set up variables)
       ...
       drawSierpinski(...);
      break;

      case '2':  // Shrinking Squares
       // (set up variables)
       ...
       drawShrinkingSquares(...);
      break;

      case '3':  // Spiral Squares
       // (set up variables)
       ...
       drawSpiralSquares(...);
      break;

      case '4':  // Circular Lace
       // (set up variables)
       ...
       drawCircularLace(...);
      break;

      case '5':  // Snowflake
       // (set up variables)
       ...
       drawSnowflake(...);
      break;

      case '6':  // Tree
       // (set up variables)
       ...
       drawTree(...);
      break;

      case '7':  // Fern
       // (set up variables)
       ...
       drawFern(...);
      break;

      case '8':  // Spiral of spirals
       // (set up variables)
       ...
       drawSpirals(...);
      break;

      case 'q':  // end program
       ...
      break;
    }
  }
  return 0;
}

// all functions go here
 
void drawSierpinski(int x1, int y1, int x2, int y2, int x3, int y3) {
  if( abs(x2-x1) < 5) {
    return;
  }
  //Draw the triangle
  gfx_line(x1, y1, x2, y2);
  gfx_line(x2, y2, x3, y3);
  gfx_line(x1, y1, x3, y3);


  // Recursive calls
  drawSierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
  drawSierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
  drawSierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}

void drawShrinkingSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){



} 

void drawSpiralSquares(){

}

void drawCircularSpace(){

}
void drawSnowflake(){

}
void drawTree(){

}
void drawFern(){

}
void drawSpirals(){

}
