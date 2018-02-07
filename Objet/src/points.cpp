#include "points.h"
#include <iostream>
using namespace std;

Point::Point(double xi, double yi, int dim){
  dimension = dim;
  x = xi;
  y = yi;
}

void Point::print(){
  cout<< "x : " << x << ", y : " << y << "\n";
}
