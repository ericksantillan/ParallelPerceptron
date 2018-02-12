#include <iostream>
#include "data.h"
#include "parallelPerceptron.h"
#include <ctime>
#include <vector>
using namespace std;

#define NB_PARTITIONS 5

int main()
{
  // Data data("../../Erick/Magic/Magic-Train1");
  // Data test_set("../../Erick/Magic/Magic-Train2");
  Data data("../../Data/Small_test.txt");
  Data test_set("../../Data/Small_test.txt");

  cout << "the nme of data is: " << test_set.filename<< endl;

  vector<Data> splitted_data = data.split(NB_PARTITIONS);

for (size_t i = 0; i < NB_PARTITIONS; i++) {
  splitted_data[i].printY();
  cout << endl;
  }

  // splitted_data = data.split(5);
  // Data first = splitted_data[0];
  // // first = splitted_data[0];
  // cout << "The number of examples in  first is: "<< first.nb_examples<< endl;
  data.openFile();
  data.populate();
  test_set.openFile();
  test_set.populate();

  ParallelPerceptron perceptron(data.nb_features);
  // Perceptron perceptron(data);

  // cout<<endl<<endl;
  clock_t begin = clock();
  cout << "[DEBUG] nb features: "<< data.nb_features << endl;
  perceptron.OneEpochPerceptron_inside(test_set, perceptron.w);
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

  cout << endl << "The training was done in "<< elapsed_secs <<" seconds" << endl;
  // perceptron.training.printX();





  //Evaluation
  // double accu = perceptron.test_accuracy(test_set);
  // cout << "Accuracy :" << accu<< endl;

  cout<< "Statistics" << endl;

  perceptron.testing(test_set);

  return 0;

}
