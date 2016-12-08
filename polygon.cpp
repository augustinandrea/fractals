#include "polygon.h"
#include "gfx.h"
#include <unistd.h>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

const int DEFAULT_RADIUS = 50;
const int VELOCITY_MIN = -20;
const int VELOCITY_MAX = 20;
const int DEFAULT_ACCELERATION = 1;
const int COLOR_MIN = 0;
const int COLOR_MAX = 255;

void gfx_color(Color c) {
  gfx_color(c.r, c.g, c.b);
}

void gfx_line(Point p1, Point p2) {
  gfx_line(
	   round(p1.x),
	   round(p1.y),
	   round(p2.x),
	   round(p2.y)
	   );
}

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

Point& Point::operator=(const Point& p) {
  if(this != &p) {
    this->x = p.x;
    this->y = p.y;
  }
  return *this;
}

// Rotate a point about a center (xc, yc)
// angle is the measure in radians of the rotation.  e.g. PI rotates 180 degrees
void Point::Rotate(double xc, double yc, double angle) {
  double newx = cos(angle)*(x - xc) - sin(angle)*(y - yc) + xc;
  double newy = sin(angle)*(x - xc) + cos(angle)*(y - yc) + yc;

  x = newx;
  y = newy;
}

Polygon::Polygon(Point center, int sides, int radius) {
  Point p;
  
  if((sides < 0) || (sides == 1) || (sides == 2)) {
    // number of sides must 0 (a circle) or 3 or greater. <0, 1, or 2 are not allowed
    cout << "Error: Attempt to create Polygon with sides: " << sides << endl;
  }
  this->sides = sides;
  this->center = center;
  this->radius = radius;

  if(sides >= 3) {
    // first point
    p.x = this->center.x - radius * cos(PI/sides);
    p.y = this->center.y + radius * sin(PI/sides);
    corners.push_back(p);
    for(int i = 1; i <= sides; i++) {
      p.Rotate(this->center.x, this->center.y, 2*PI/sides);
      corners.push_back(p);
      cout << "(" << p.x << "," << p.y << ")" << endl;
    }
  }
  color = WHITE;
  angle = 0.0;
}

void Polygon::Draw() {
  for(auto i = 0; i < corners.size() - 1; i++){
    gfx_line(
	     round(corners[i].x),
	     round(corners[i].y),
	     round(corners[i+1].x),
	     round(corners[i+1].y));
  }
}

void Polygon::Rotate(double angle) {
}
