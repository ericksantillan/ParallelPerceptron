#include "parallelPerceptron.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <assert.h>

ParallelPerceptron::ParallelPerceptron(int features){
  nb_features = features;
  w = new double[nb_features];
  for (size_t i = 0; i < nb_features; i++) {
    w[i] = 0.0;
  }
}

double ParallelPerceptron::fw(double* x, double* wp){
  double dot_product = 0.0;
  for (size_t i = 0; i < nb_features; i++) {
    dot_product += wp[i] * x[i];
  }
  if (dot_product <= 0.0) {
    return -1.0;
  } else {
    return 1.0;
  }
}

double ParallelPerceptron::f(double* x){
  double dot_product = 0.0;
  for (size_t i = 0; i < nb_features; i++) {
    dot_product += w[i] * x[i];
  }
  if (dot_product <= 0.0) {
    return -1.0;
  } else {
    return 1.0;
  }
}

void ParallelPerceptron::setW(double* wp){
  for (size_t i = 0; i < nb_features; i++) {
    w[i] = wp[i];
  }

}

void ParallelPerceptron::OneEpochPerceptron_inside(Data training_set, double* wp, int max_iterations){
  setW(wp);
  srand (time(NULL));
  int sample;
  for (size_t t = 0; t < max_iterations; t++) {
    sample = rand() % training_set.nb_examples;
    if(training_set.y[sample] * f(training_set.X[sample]) < 0.0){
      for (size_t i = 0; i < nb_features; i++) {
        w[i] += learning_rate * training_set.y[sample]* training_set.X[sample][i];
      }
    }
  }

}


// double* ParallelPerceptron::OneEpochPerceptron(Data training_set, double* wp, int max_iterations ){
//   double w_in = new double[nb_features];
//   srand (time(NULL));
//   int sample;
//   //copy w into w_in
//   for (size_t i = 0; i < training_set.nb_features; i++) {
//     w_in[i] = wp[i];
//   }
//   for (size_t t = 0; t < max_iterations; t++) {
//     sample = rand() % training.nb_examples;
//     if (training_set.y[sample] * f) {
//       /* code */
//     }
//   }
//   return w_in;
// }

void ParallelPerceptron::printW(){
  for (size_t i = 0; i < nb_features; i++) {
    cout<<"W["<<i<<"]: "<< w[i] << endl;
  }
}

void ParallelPerceptron::testing(Data test_set){
  int total_positif = 0;
  int total_negatif = 0;
  int true_positif = 0;
  int true_negatif = 0;
  int false_positif = 0;
  int false_negatif = 0;
  double predict = 0.0;
  for (size_t i = 0; i < test_set.nb_examples; i++) {
    predict = f(test_set.X[i]);
    if (test_set.y[i] > 0.0) {
      total_positif++;
      if (predict > 0.0) {
        true_positif++;
      } else {
        false_positif++;
      }
    }
    else{
      total_negatif ++;
      if (predict < 0.0) {
        true_negatif++;
      } else {
        false_negatif++;
      }
    }
  }
  cout << "Total positif " << total_positif << endl;
  cout << "Total negatif " << total_negatif << endl << endl;
  cout << "True positif " << true_positif << endl;
  cout << "True negatif " << true_negatif << endl;
  cout << "False positif " << false_positif << endl;
  cout << "False negatif " << false_negatif << endl << endl;

  cout << "Accuracy: " << double(true_negatif + true_positif) / double(total_negatif + total_positif) << endl;
}
