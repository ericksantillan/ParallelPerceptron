#ifndef PARALLELPERCEPTRON_H
#define PARALLELPERCEPTRON_H

#include "data.h"

#define MAX_ITER 50000

class ParallelPerceptron{
public:
  int nb_features;
  double* w;
  double learning_rate = 0.1;
  ParallelPerceptron(int features);
  void setW(double* wp);
  double f( double* x);
  void printW();
  void testing(Data& test_set);
  double fw(double* x, double* wp);
  void OneEpochPerceptron_inside(Data& training_set, double* wp, int max_iterations = MAX_ITER);
};

#endif
