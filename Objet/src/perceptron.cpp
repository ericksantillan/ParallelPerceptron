#include "perceptron.h"

Perceptron::Perceptron(Data data){
  training = new Data(data);
  w = new double[training.nb_features];
  for (size_t i = 0; i < training.nb_features; i++) {
    w[i] = 0.0;
  }
}
