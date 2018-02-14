#include <iostream>
#include <ctime>
#include <vector>
#include <omp.h>

#include "data.h"
#include "parallelPerceptron.h"
#include "PerceptronIterParamMix.h"

using namespace std;

#define NB_PARTITIONS 5
#define NB_THREADS 2

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
  Data test_set(argv[2]);
  cout << ". Done" << endl;



  training_set.openFile();
  test_set.openFile();
  test_set.populate();

  PerceptronIterParamMix perceptron(training_set.nb_features, NB_PARTITIONS );

  cout << "Starting training" << endl;
  double start_time = omp_get_wtime();
  perceptron.train( training_set );
  double run_time = omp_get_wtime() - start_time;
  cout << "Finished"<< endl;
  cout << endl << "The training was done in "<< run_time <<" seconds" << endl;

  perceptron.test(test_set);

  return 0;
}
