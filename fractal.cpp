// candidate for overall structure of the fractals program
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "gfx.h"
#include "polygon.h"

// function prototypes
void drawSierpinski(int x1, int y1, int x2, int y2, int x3, int y3);
void drawShrinkingSquares(int x1, int y1, int side);
void drawSpiralSquares(int xc, int yc, float radius, float theta);
void drawCircularLace(int x, int y, int radius);
void drawSnowflake(int x, int y, int length);
void drawTree();
void drawFern();
void drawSpirals();

int main() {

  // variables
  char c;  
  int wd = 1000;
  int ht = 1000;

  gfx_open(wd, ht, "Fractals");

  while ((c = gfx_wait()) != 'q') {

    gfx_clear();

    switch (c) {
    case '1':  // Sierpinski Triangle   
      drawSierpinski(wd/2, ht, 0, 0, wd, 0);
      break;

    case '2':  // Shrinking Squares
      drawShrinkingSquares(wd/4, ht/4, wd/2);
      break;

    case '3':  // Spiral Squares
      drawSpiralSquares(wd/2,ht/2,1,0);
      break;

    case '4':  // Circular Lace
      drawCircularLace(wd/2, ht/2, wd/3);
      break;
      
    case '5':  // Snowflake
      drawSnowflake(wd/2, ht/2, wd/3);
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

void drawShrinkingSquares(int x, int y, int side) {
  if(side < 2) {
    return;
  }

  //Draw the square
  gfx_line(x, y, x+side, y);
  gfx_line(x+side, y, x+side, y+side);
  gfx_line(x+side, y+side, x, y+side);
  gfx_line(x, y+side, x, y);
    
  //Recursive calls
  drawShrinkingSquares(x-side/5, y-side/5, 2*side/5);
  drawShrinkingSquares(x+(side-side/5), y-side/5, 2*side/5);
  drawShrinkingSquares(x+(side-side/5), y+(side-side/5), 2*side/5);
  drawShrinkingSquares(x-side/5, y+(side-side/5), 2*side/5);

} 

void drawSpiralSquares(int xc, int yc, float radius, float theta){
  if (radius > 500) {
    return; 
  }
  Polygon p(Point(xc, yc), 4, radius);
  p.Draw();
  int newx = round(2.5*radius*cos(theta)+xc);
  int newy = round(2.5*radius*sin(theta)+yc);

  drawSpiralSquares(newx, newy, radius*1.025, theta+PI/12);
}

void drawCircularLace(int x, int y, int radius) {
  if(radius < 2) {
    return;
  }
  
  // draw the circle
  gfx_circle(x, y, radius);

  int nr = radius/3;
  //recursion
  drawCircularLace(x-radius, y, nr);
  drawCircularLace(x+radius, y, nr);
  drawCircularLace(x-cos(2*PI/6)*radius, y-sin(2*PI/6)*radius, nr);
  drawCircularLace(x+cos(2*PI/6)*radius, y-sin(2*PI/6)*radius, nr);
  drawCircularLace(x-cos(2*PI/6)*radius, y+sin(2*PI/6)*radius, nr);
  drawCircularLace(x+cos(2*PI/6)*radius, y+sin(2*PI/6)*radius, nr);
}


void drawSnowflake(int x, int y, int length) {

  if(length < 2) {
    return;
  }

  int nl = length/3;
  Point points[5];
  Point center(x,y);
  
  points[0].x = x;
  points[0].y = y + length;
  gfx_line(center, points[0]);
  drawSnowflake(points[0].x, points[0].y, nl);

  for(int i = 1; i < 5; i++) {
    points[i] = points[i-1];
    points[i].Rotate(x, y, 2*PI/5);
    gfx_line(center, points[i]);
    drawSnowflake(points[i].x, points[i].y, nl);    
  }

}

/*
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
