#ifndef PERCEPTRON_H
#define PERCEPTRON_H


#include "data.h"

class Perceptron{
public:
  Data training;
  double* w;
  Perceptron(Data data);
};

#endif
