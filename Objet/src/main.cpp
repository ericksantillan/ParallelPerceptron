#include <iostream>
#include "data.h"
using namespace std;

int main()
{
  // Data data("../../Erick/Magic/Magic-Train1");
  Data data("../Test.txt");
  // data.print();
  data.openFile();
  data.print();
  data.populate();

  cout<< "The First line of  X is:"<< endl;
  for (size_t i = 0; i < data.nb_features; i++) {
    cout<< data.X[1][i] << "\t";
  }
  cout<< endl;
  return 0;
}
