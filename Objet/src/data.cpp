#include "data.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

Data::Data(const string& file):filename(file){
  // filename = file;
}

Data::Data(const Data& data){
  filename = data.filename;
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
  nb_examples = i;
  nb_features = k;
}

void Data::populate(){
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
    i++;
  }
}

void Data::printX(){
  if( (nb_examples == -1) or (nb_features == -1)){
    throw string("Number of examples or number of features not initialized");
  }
  for (size_t i = 0; i < nb_examples; i++) {
    for (size_t j = 0; j < nb_features; j++) {
          cout<< "X["<<i<<"]["<<j<<"]: "<<X[i][j] << "\t";
    }
    cout<<endl;
  }
}

void Data::printY(){
  if( (nb_examples == -1) or (nb_features == -1)){
    throw string("Number of examples or number of features not initialized");
  }
  for (size_t i = 0; i < nb_examples; i++) {
    cout<< "Y["<<i<<"]: "<<y[i] << "\t";
  }
  cout<<endl;
}
