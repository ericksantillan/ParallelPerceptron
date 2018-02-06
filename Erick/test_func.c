#include "utils.h"
#include <stdlib.h>

int main(int argc, char **argv){
  const int d=4;
  double *X = malloc(sizeof(double)*d);
  double *wN = malloc(sizeof(double)*d);
  double *wP = malloc(sizeof(double)*d);

  for (size_t i = 0; i < d; i++) {
    X[i]= 1.0;
    wP[i] = 2.0;
    wN[i] = -1.0;
  }
  // for (size_t i = 0; i < d; i++) {
  //   printf("X[%i] = %f\n",i,X[i] );
  // }

  // double X[4] = {1.0,1.0,1.0,1.0};
  // double w[4] = {1.0,0.0,1.0,0.0};
  double prod;
  prod = dot(X,X,d);
  int fn, fp;
  fn = f(X,wN,d);
  fp = f(X,wP,d);
  printf("f postif: %i\n",fp );
  printf("f null: %i\n",fn );

  return 0;
}
