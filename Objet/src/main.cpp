#include <iostream>
#include "data.h"
#include "perceptron.h"
using namespace std;

int main()
{
  // Data data("../../Erick/Magic/Magic-Train1");
  Data data("../Test.txt");
  // data.print();

  // data.printX();

  data.openFile();
  data.print();
  data.populate();

  Perceptron perceptron(data);

  cout<<endl<<endl;
  perceptron.training.print();

  perceptron.training.printX();
  perceptron.training.printY();
//   cout<< endl;
//   for (size_t j = 0; j < data.nb_examples; j++) {
//     cout<< data.y[j]<<"\t";
//   for (size_t i = 0; i < data.nb_features; i++) {
//     cout<< data.X[j][i] << "\t";
//   }
//   cout<< endl;
// }
  return 0;
}
