// candidate for overall structure of the fractals program
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "gfx.h"

// function prototypes
void drawSierpinski(int x1, int y1, int x2, int y2, int x3, int y3);
void drawShrinkingSquares();
void drawSpiralSquares();
void drawCircularLace();
void drawSnowflake();
void drawTree();
void drawFern();
void drawSpirals();

const double PI = 3.14159;


int main() {

  // variables
  char c;  
  int wd = 600;
  int ht = 600;

  gfx_open(wd, ht, "Fractals");

  while (gfx_wait() != 'q') {
    c = gfx_wait();
    gfx_clear();

    switch (c) {
    case '1':  // Sierpinski Triangle   
      // (set up variables)
      drawSierpinski(wd/2, 0, 0, ht, wd, ht);
      break;

    case '2':  // Shrinking Squares
      // (set up variables)
       
      //      drawShrinkingSquares();
      break;

    case '3':  // Spiral Squares
      // (set up variables)
       
      //      drawSpiralSquares();
      break;

    case '4':  // Circular Lace
      // (set up variables)
      
      //      drawCircularLace();
      break;
      
    case '5':  // Snowflake
      // (set up variables)
      
      //      drawSnowflake();
      break;
      
    case '6':  // Tree
      // (set up variables)
      
      //      drawTree();
      break;
      
    case '7':  // Fern
      // (set up variables)
      
      //      drawFern();
      break;
      
    case '8':  // Spiral of spirals
      // (set up variables)
      
      //      drawSpirals();
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
/*
void drawShrinkingSquare(int xc, int yc, float radius, float theta){
  if(radius < 5) {
    return;
  }

  //Draw the square
  gfx_line(x1,y1,x2,y2);
  gfx_line(x2,y2,x3,y3);
  gfx_line(x3,y3,x4,y4);
  gfx_line(x4,y4,x1,y1);

  //Recursive calls
  drawShrinkingSquare(xc, yc, radius/2, theta*cos(PI/6));
  drawShrinkingSquare(xc, yc);
  drawShrinkingSquare();
  drawShrinkingSquare();

} 

void drawSpiralSquares(int xc, int yc, float radius,float theta, int length){
  if (radius < 5) {
    return; 
  }

  //Draw the square
  gfx_line(x1,y1,x2,y2);
  gfx_line(x2,y2,x3,y3);
  gfx_line(x3,y3,x4,y4);
  gfx_line(x4,y4,x1,y1);

  //recursion
  drawSpiralSquares(xc,yc,radius,theta*cos(PI/6),length/2);
  drawSpiralSquares(xc,yc, radius-PI, theta*cos(PI/6), length/2);



}

void drawCircularLace(float radius, int xc, int yc){
  if(radius < 5){
    return;
  }
  
  // draw the circle
  gfx_circle(xc, yc, radius);

  radius = radius*0.5;
  //recursion
  drawCircularLace(xc, yc, radius/2);
  drawCircularLace(xc);
  drawCircularLace();
}
void drawSnowflake(int xcenter, int ycenter, float x1, float y1){
  if(length < 5) {
    return;
  }

  


  gfx_line(xc,yc,x1,y1);
  gfx_line(xc,yc,x1,y2);
  gfx_line(xc,yc,x2,y2);
  gfx_line(xc,yc,x3,y3);

}
void drawTree(float radius, int xcenter, int ycenter, int x, int y, float theta){
  if(radius < 8) {
    return;
  }
  //draw line
  gfx_line(x1,y1,x2,y2,length);
  

  length *= PI/3;
  


  //recursion
  drawTree(,);
  }


}
void drawFern(float length,int x1, int y1, int x2, int y2){
  if(length < 5) {
    return;
  }
  //draw line
  gfx_line(x1, y1, x2, y2);
  float rotate = PI/6;
  //recursion
  drawFern();

}
void drawSpirals(float radius, int xcenter, int ycenter, int x, int y){
  if(radius < 5) {
    return;
  }

  // drawing the point
  gfx_point(x, y);

  // Recursion
  drawSpirals(radius);

}
*/
