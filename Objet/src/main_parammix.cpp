#include <iostream>
#include <ctime>
#include <vector>
#include <omp.h>

#include "data.h"
#include "parallelPerceptron.h"
#include "PerceptronIterParamMix.h"

using namespace std;

#define NB_PARTITIONS 5
#define NB_THREADS 1

int main(int argc, char const *argv[]) {
  cout << "********* MAIN PARALLEL ITERATIVE PARAMETRE MIX PERCEPTRON ************" << endl << endl;
  omp_set_num_threads(NB_THREADS);


  if (argc < 2) {
    cout << "Please call the program as ./main_parallel ./Path/to/Data.txt"<< endl;
    return 0;
  }

  cout << "Creating dataFrame.";
  Data training_set(argv[1]);
  cout << ".";
  Data test_set(argv[1]);
  cout << ". Done" << endl;



  training_set.openFile();
  test_set.openFile();
  test_set.populate();

  PerceptronIterParamMix perceptron(training_set.nb_features, NB_PARTITIONS );

  cout << "Starting training" << endl;
  clock_t begin = clock();
  perceptron.train( training_set );
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << "Finished"<< endl;
  cout << endl << "The training was done in "<< elapsed_secs <<" seconds" << endl;

  perceptron.test(test_set);

  return 0;
}
