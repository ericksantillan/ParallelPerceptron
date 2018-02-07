#include "data.h"
#include <iostream>
#include <fstream>

using namespace std;

Data::Data(const string& file):filename(file){
  // filename = file;
}

void Data::print(){
  cout << "The file name is: " << filename << "\n";
}


void Data::openFile(){
  ifstream infile(filename);
  string line;
  while(getline(infile, line)){
    cout<<line<<endl;
  }
}
