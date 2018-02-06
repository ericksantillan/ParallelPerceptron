#include "utils.h"

double dot(double *X, double *w, int d){
  int j;
  float ProdScal;
  for(ProdScal=w[0], j=0; j<d; j++){
    // printf("w[%i] = %f\t x[%i] = %f\n",j,w[j] ,j,X[j]);
     ProdScal+=w[j]*X[j];}
  return ProdScal;
}

int f(double *x, double *w, int d){
  double dotProd = dot(x, w,d);
  if (dotProd > 0.0)
    return 1;
  return 0;
}


void OneEpochPerceptron(double **X, double *Y, double *w, int d, int T ){
  int k =0;
  int iter_y=0;
  double max_y = 0.0;
  for (size_t t = 0; t < T; t++) {
    k = k+1;
  }
  return 5;
}

void mixParams(double *w1, double *w2, double *w, int d){
  int nb_partitions  = 2;
  double mu[2] = {0.6, 0.4};
  for (size_t k = 0; k < d; k++) {
      w[k] = mu[0] * w1[i] + mu[2]*w2[i]
  }
  printf("\n" );
}


void FileScan(char *filename, long int *m, long int *d)
{
   FILE *fd;
   long int  i=0, ch, prev='\n', dim=0, lines=0;
   char *str, sep[]=": \t";

   str=(char *)malloc(MAXSTR*sizeof(char ));

   if((fd=fopen(filename,"r"))==NULL){
     perror(filename);
     exit(0);
   }
   while((ch=fgetc(fd)) != EOF){
     if(!lines)
        str[i++]=ch;

     if(ch=='\n')
        ++lines;

     prev=ch;
   }
   fclose(fd);
   if(prev != '\n')
      ++lines;

   i--;
   str[i]='\0';
   str=strtok(str,sep);
   str=strtok((char *)NULL,sep);
   while(str)
   {
      str=strtok((char *)NULL,sep);
      dim++;
   }
   *m=lines;
   *d=dim;

   free((char *) str);
}
