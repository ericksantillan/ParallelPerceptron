#include "perceptron.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <assert.h>

Perceptron::Perceptron(Data data):training(data){
  // training = new Data(data);
  w = new double[training.nb_features];
  for (size_t i = 0; i < training.nb_features; i++) {
    w[i] = 0.0;
  }
}

void Perceptron::train(){
  srand (time(NULL));
  int sample;
  int reu = 0;
  for (size_t t = 0; t < MAX_ITER; t++) {
    sample = rand() % training.nb_examples;
    if (training.y[sample] * f( training.X[sample] ) < 0 ) {
      //Updating w
      reu++;
      for (size_t i = 0; i < training.nb_features; i++) {
        w[i] += learning_rate * training.y[sample]* training.X[sample][i];
      }
    }
  }
  cout << "Update " << reu << "times"<<endl;
}

double Perceptron::f(double* x){
  double dot_product = 0.0;
  for (size_t i = 0; i < training.nb_features; i++) {
    dot_product += w[i] * x[i];
  }
  if (dot_product <= 0.0) {
    return -1.0;
  } else {
    return 1.0;
  }
}

void Perceptron::printW(){
  for (size_t i = 0; i < training.nb_features; i++) {
    cout<<"W["<<i<<"]: "<< w[i] << endl;
  }
}

double Perceptron::test_accuracy(Data test_set){
  // cout << "Test features :" << test_set.nb_features << "Training features: " << training.nb_features << endl;
  assert( test_set.nb_features ==  training.nb_features);
  double accuracy = 0.0;
  double predict = 0.0;
  int bons = 0;
  for (size_t i = 0; i < test_set.nb_examples; i++) {
    predict = f(test_set.X[i]);
    if ((test_set.y[i] * predict) > 0.0 ) {
      accuracy += 1.0;
      bons++;
    }
  }
  return (accuracy/ test_set.nb_examples);
}

void Perceptron::testing(Data test_set){
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
  cout << "False negatif " << false_negatif << endl;

}
