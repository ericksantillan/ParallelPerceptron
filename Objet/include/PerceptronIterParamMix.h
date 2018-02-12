#ifndef PERCEPTRONITERPARAMMIX_H
#define PERCEPTRONITERPARAMMIX_H

#include <vector>
#include "ParallelPerceptron.h"
using namespace std;


class PerceptronIterParamMix{
public:
  vector<ParallelPerceptron> list_perceptrons;
  PerceptronIterParamMix(int nb_perceptrons);
};


#endif
