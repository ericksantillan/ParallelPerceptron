#include "data.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <assert.h>

using namespace std;

Data::Data(const string& file, bool inter):filename(file),intercept(inter){
  // filename = file;
}

Data::Data(const Data& data){
  filename = data.filename;
  intercept = data.intercept;
  openFile();
  populate();
}

void Data::print(){
  cout << "The file name is: " << filename << "\n";
  cout << "The number of examples is: " << nb_examples << "\n";
  cout << "The number of features is: " << nb_features << "\n";

}


void Data::openFile(){
  int i = 0;
  size_t k = 0;
  bool first = true;
  //Opening file
  ifstream infile(filename);
  string line;
  //Reading file
  while(getline(infile, line)){
    // cout<<line<<endl;
    if (first){
      k = count(line.begin(), line.end(), ' ');
      first = false;
    }
    i++;
  }
  // cout << "There is "<< k << "times in the line"<< endl;
  // cout << i;

  if (intercept) {
    k++;
  }

  nb_examples = i;

  nb_features = k;
}

/**
  * This function read the data from the file in filename
  * The data should be formatted as follows: First the label in float (-1.0 or 1.0)
  * Then the features separeted by ONE space
  * The intercept will be added as the last feature if needed
  */
void Data::populate(){
  assert(nb_examples > 0 and nb_features > 0);

  //Allocation of memory
  X = new double* [nb_examples];
  for (size_t i = 0; i < nb_examples; i++) {
    X[i] = new double[nb_features];
  }
  y = new double[nb_examples];

  //Population
  ifstream infile(filename);
  string line;
  string label;
  string feature;
  int i = 0;
  int j = 0;
  while (getline(infile, line)) {
    stringstream st(line);
    getline(st, label, ' ');
    y[i] = stof(label);
    j=0;
    // cout<<"Filling line"<<endl<<endl;
    while(getline(st, feature, ' ')){
      X[i][j] = stof(feature);
      // cout<< "X["<< i <<"]["<<j<<"]: "<< X[i][j]<<endl;
      j++;
    }
    if (intercept) {
      X[i][j] = 1.0;
    }
    i++;
  }
}

void Data::printX(){
  assert(nb_examples > 0 and nb_features > 0);
  for (size_t i = 0; i < nb_examples; i++) {
    for (size_t j = 0; j < nb_features; j++) {
          cout<< "X["<<i<<"]["<<j<<"]: "<<X[i][j] << "\t";
    }
    cout<<endl;
  }
}

void Data::printY(){
  assert(nb_examples > 0 and nb_features > 0);
  for (size_t i = 0; i < nb_examples; i++) {
    cout<< "Y["<<i<<"]: "<<y[i] << "\t";
  }
  cout<<endl;
}
