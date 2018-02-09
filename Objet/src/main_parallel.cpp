#include <iostream>
#include "data.h"
#include "parallelPerceptron.h"
#include <ctime>
using namespace std;

int main()
{
  // Data data("../../Erick/Magic/Magic-Train1");
  // Data test_set("../../Erick/Magic/Magic-Train2");
  Data data("../../Data/Magic-Train1");
  Data test_set("../../Data/Magic-Train2");

  data.openFile();
  data.populate();
  test_set.openFile();
  test_set.populate();

  ParallelPerceptron perceptron(data.nb_features);
  // Perceptron perceptron(data);

  // cout<<endl<<endl;
  clock_t begin = clock();
  perceptron.OneEpochPerceptron_inside(data, perceptron.w);
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
