#include "PerceptronIterParamMix.h"
#include <omp.h>

PerceptronIterParamMix::PerceptronIterParamMix(int features, int nb_perceptrons){
  nb_features = features;
  for (int i = 0; i < nb_perceptrons; i++) {
    list_perceptrons.push_back(ParallelPerceptron(nb_features));
  }
  // list_perceptrons = vector<ParallelPerceptron>(nb_perceptrons);
  W = new double[nb_features];
  for (int i = 0; i < nb_features; i++) {
    W[i] = 0.0;
  }

}

void PerceptronIterParamMix::train(Data& training_set){
  int nb_partitions = list_perceptrons.size();
  size_t i;
  vector<Data> list_data = training_set.split(nb_partitions);
  for (int n = 0; n < N; n++) {
    //Parallelizable
    total_errors = 0;
    // #pragma omp parallel for default(shared) private(i) //reduction(+:dot_product)
    for (i = 0; i < list_perceptrons.size(); i++) {
      list_perceptrons[i].OneEpochPerceptron_inside( list_data[i], W );
      total_errors += list_perceptrons[i].nb_updates;
    }
    //Update W
    for (int k = 0; k < nb_features; k++) {
      for (size_t i = 0; i < list_perceptrons.size(); i++) {
        W[k] +=( double(list_perceptrons[i].nb_updates) / total_errors ) * list_perceptrons[i].w[k];
      }
    }
  }
}

double PerceptronIterParamMix::f(double* x){
  double dot_product = 0.0;
  for (int i = 0; i < nb_features; i++) {
    dot_product += W[i] * x[i];
  }
  if (dot_product <= 0.0) {
    return -1.0;
  } else {
    return 1.0;
  }
}

void PerceptronIterParamMix::test(Data& test_set){
  int total_positif = 0;
  int total_negatif = 0;
  int true_positif = 0;
  int true_negatif = 0;
  int false_positif = 0;
  int false_negatif = 0;
  double predict = 0.0;
  for (int i = 0; i < test_set.nb_examples; i++) {
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
