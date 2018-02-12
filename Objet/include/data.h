#ifndef DATA_H
#define DATA_H


#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Data{
public:
  string filename;
  double **X; //Training set
  double *y;
  int nb_examples = -1; //number of examples
  int nb_features = -1; //number of features
  bool intercept;
  // Data(bool inter = true);
  Data(const string& file, bool inter = true);
  Data(const Data& data);
  void print();
  void printX();
  void printY();
  void openFile();
  void populate();
  vector<Data> split(int nb_partitions);
  void setFilename(string file);
private:
  void allocateMemory();
};

#endif
