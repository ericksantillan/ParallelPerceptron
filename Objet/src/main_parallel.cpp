#include <iostream>
#include "data.h"
#include "parallelPerceptron.h"
#include <ctime>
#include <vector>
#include <omp.h>
using namespace std;

#define NB_PARTITIONS 5
#define NB_THREADS 1


int main3(int argc, char const *argv[])
{
  // Data data("../../Erick/Magic/Magic-Train1");
  // Data test_set("../../Erick/Magic/Magic-Train2");
  // Data data("../../Data/Small_test.txt");
  // Data test_set("../../Data/Small_test.txt");

  omp_set_num_threads(NB_THREADS);


  if (argc < 2) {
    cout << "Please call the program as ./main_parallel ./Path/to/Data.txt"<< endl;
    return 0;
  }

  cout << "Creating dataFrame.";
  Data data(argv[1]);
  cout << ".";
  Data test_set(argv[1]);
  cout << ". Done" << endl;

  // vector<Data> splitted_data = data.split(NB_PARTITIONS);


  // splitted_data = data.split(5);
  // Data first = splitted_data[0];
  // // first = splitted_data[0];
  // cout << "The number of examples in  first is: "<< first.nb_examples<< endl;
  cout<< "Parsing data."<<endl;
  data.openFile();
  data.populate();
  cout<< "."<<endl;
  test_set.openFile();
  test_set.populate();
  cout << ". Done"<< endl;

  ParallelPerceptron perceptron(data.nb_features);

  cout<< "Trainig..."<< endl;
  clock_t begin = clock();
  perceptron.OneEpochPerceptron_inside(test_set, perceptron.w);
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << " Done"<< endl;
  cout << endl << "The training was done in "<< elapsed_secs <<" seconds" << endl;
  // perceptron.training.printX();





  //Evaluation
  // double accu = perceptron.test_accuracy(test_set);
  // cout << "Accuracy :" << accu<< endl;

  cout<< endl << "Testing..." << endl;

  perceptron.testing(test_set);

  return 0;

}
