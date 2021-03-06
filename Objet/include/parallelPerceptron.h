#ifndef PARALLELPERCEPTRON_H
#define PARALLELPERCEPTRON_H

#include "data.h"

#define MAX_ITER 50000

class ParallelPerceptron{
public:
  int nb_features;
  double* w;
  double learning_rate = 0.01;
  ParallelPerceptron(int features);
  int nb_updates = 0; //Number of updates made on the last training_set
  ParallelPerceptron(const ParallelPerceptron& P);
  void setW(double* wp);
  double f( double* x);
  void printW();
  void testing(Data& test_set);
  double fw(double* x, double* wp);
  void OneEpochPerceptron_inside(Data& training_set, double* wp, int max_iterations = MAX_ITER);
};

#endif
