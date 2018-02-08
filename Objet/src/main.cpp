#include <iostream>
#include "data.h"
#include "perceptron.h"
using namespace std;

int main()
{
  // Data data("../../Erick/Magic/Magic-Train1");
  // Data test_set("../../Erick/Magic/Magic-Train2");
  Data data("../../Data/tmp.txt");
  Data test_set("../../Data/tmp.txt");

  test_set.openFile();
  test_set.populate();

  Perceptron perceptron(data);

  // cout<<endl<<endl;
  perceptron.training.print();
  perceptron.training.printX();

  //Training
  perceptron.train();



  //Evaluation
  double accu = perceptron.test_accuracy(test_set);
  cout << "Accuracy :" << accu<< endl;

  cout<< "Statistics" << endl;

  perceptron.testing(test_set);

  return 0;

}
