#ifndef DATA_H
#define DATA_H


#include <string>
#include <iostream>
using namespace std;

class Data{
public:
  string filename;
  double **X; //Training set
  double *y;
  int nb_examples = -1; //number of examples
  int nb_features = -1; //number of features
  bool intercept;
  Data(const string& file, bool inter = true);
  Data(const Data& data);
  void print();
  void printX();
  void printY();
  void openFile();
  void populate();
};

#endif
