#include <iostream>
#include "data.h"
#include "perceptron.h"
#include <ctime>
using namespace std;

int main()
{
  // Data data("../../Erick/Magic/Magic-Train1");
  // Data test_set("../../Erick/Magic/Magic-Train2");
  Data data("../../Data/test.txt");
  Data test_set("../../Data/test.txt");

  test_set.openFile();
  test_set.populate();

  Perceptron perceptron(data);

  // cout<<endl<<endl;

  perceptron.training.print();

  // perceptron.training.printX();

  //Training
  clock_t begin = clock();
  perceptron.train();
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

  cout << endl << "The training was done in "<< elapsed_secs <<" seconds" << endl;


  //Evaluation
  double accu = perceptron.test_accuracy(test_set);
  cout << "Accuracy :" << accu<< endl;

  cout<< "Statistics" << endl;

  perceptron.testing(test_set);

  return 0;

}
