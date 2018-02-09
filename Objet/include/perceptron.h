#ifndef PERCEPTRON_H
#define PERCEPTRON_H


#include "data.h"

#define MAX_ITER 500000

class Perceptron{
public:
  Data training;
  double* w;
  double learning_rate = 0.1;
  Perceptron(Data data);
  Perceptron();
  void train();
  double f( double* x);
  void printW();
  double test_accuracy(Data test_set);
  void testing(Data test_set);
};

#endif
