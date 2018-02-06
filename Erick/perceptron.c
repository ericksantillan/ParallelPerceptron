#include <stdlib.h>
#include <string.h>
#include "utils.h"

// int NBPARTITIONS =2;

char* concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1+len2+1);//+1 for the null-terminator
    //in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result+len1, s2, len2+1);//+1 to copy the null-terminator
    return result;
}


// int OneEpochPerceptron(double **X, double *Y, double *w, int T ){
//   for (size_t t = 0; t < T; t++) {
//     printf("Hey\n" );
//   }
//   return 5;
// }

int main(int argc, char **argv){
  int S = 2; //number of division of the training SET
  long int m1, d1, m2, d2;
  double     *w1, *Y1, **X1;
  double     *w2, *Y2, **X2;
  double     *w;

  long int T = 5;
  const char *list_of_files[S];
  list_of_files[0] = "./Magic/Magic-Train1";
  list_of_files[1] = "./Magic/Magic-Train2";

  int i = 0;
  for (i = 0; i < S; i++) {
    printf("The list of files in %u has: %s\n",i,list_of_files[i] );
  }

  FileScan(list_of_files[0],&m1,&d1);
  printf("File 1: m: %u, d: %u\n", m1, d1);

  FileScan(list_of_files[0],&m2,&d2);
  printf("File 2: m: %u, d: %u\n", m2, d2);

  //Init first variables X1, Y1, w1
  printf("Initializing variables\n" );
  Y1  = (double *)  malloc((m1+1)*sizeof(double ));
  X1  = (double **) malloc((m1+1)*sizeof(double *));
  if(!X1){
    printf("Memory allocation problem (1)\n");
    exit(0);
  }
  X1[1]=(double *)malloc((size_t)((m1*d1+1)*sizeof(double)));
  if(!X1[1]){
    printf("Memory allocation problem (2)\n");
    exit(0);
  }
  for(i=2; i<=m1; i++)
    X1[i]=X1[i-1]+d1;
  w1  = (double *) malloc((d1+1) * sizeof(double ));
  // printf("Finish init\n" );

  //Initializing variables X2,Y2,w2
  // printf("Initializing variables\n" );
  Y2  = (double *)  malloc((m2+1)*sizeof(double ));
  X2  = (double **) malloc((m2+1)*sizeof(double *));
  if(!X2){
    printf("Memory allocation problem (1)\n");
    exit(0);
  }
  X2[1]=(double *)malloc((size_t)((m2*d2+1)*sizeof(double)));
  if(!X2[1]){
    printf("Memory allocation problem (2)\n");
    exit(0);
  }
  for(i=2; i<=m2; i++)
    X2[i]=X2[i-1]+d2;
  w2  = (double *) malloc((d2+1) * sizeof(double ));
  w  = (double *) malloc((d2+1) * sizeof(double ));

  printf("Finish init\n" );



  //LEARNING algorithm:
  printf("Init learning algorithm\n");

  int N = 10;
  for (size_t n = 0; n < N; n++) {
    OneEpochPerceptron(X1,Y1,w1,d1,T);
    OneEpochPerceptron(X2,Y2,w2,d2,T);
    mixParams(w1,w2,w,d1);

  }




  printf("Finish!\n");

  return 1;
}
