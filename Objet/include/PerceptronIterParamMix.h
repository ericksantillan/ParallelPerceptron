#ifndef PERCEPTRONITERPARAMMIX_H
#define PERCEPTRONITERPARAMMIX_H

#include <vector>
#include "data.h"
#include "parallelPerceptron.h"
using namespace std;


class PerceptronIterParamMix{
public:
  int nb_features;
  vector<ParallelPerceptron> list_perceptrons;
  double* W;
  int N = 100;
  int total_errors = 0;
  PerceptronIterParamMix(int nb_features, int nb_perceptrons);

  void train(Data& training_set);
  double f(double* x);
  void test(Data& test_set);
};


#endif
