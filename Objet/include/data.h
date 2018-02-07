#include <string>
#include <iostream>
using namespace std;

class Data{
public:
  string filename;
  double **x;
  double *y;
  int nb_examples; //number of examples
  int nb_features; //number of features

  Data(const string& file);
  void print();
  void openFile();
};
