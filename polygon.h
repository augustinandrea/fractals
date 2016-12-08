#ifndef BALL_H
#define BALL_H

#include <vector>

using namespace std;

class Color {
 public:
  int r, g, b;
  Color(int red, int green, int blue) {r = red; g = green; b = blue;};
  Color() {r=g=b=0;};
};

const Color BLACK = Color(0,0,0);
const Color WHITE = Color(255,255,255);
const Color RED =   Color(255,0,0);
const Color GREEN = Color(0,255,0);
const Color BLUE =  Color(0,0,255);

void gfx_color(Color c);

static const double PI = 3.14159;

class Point {
 public:
  Point(double, double);
  Point& operator=(const Point& p);
  Point(){x=0; y=0;};
  double x, y;
  void Rotate(double cx, double cy, double angle);
};

void gfx_line(Point p1, Point p2);

typedef vector<Point> point_vector_t;

class Polygon {
 public:
  Polygon(Point center, int sides, int radius);
  void Draw();
  void Rotate(double angle);

  Color color;
  int sides;
  int radius;
  point_vector_t corners;
  Point center;
  double angle;
};

#endif
