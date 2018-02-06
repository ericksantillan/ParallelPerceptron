#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSTR    1e8

double dot(double *X, double *w, int d);
int f(double *x, double *w, int d);
void OneEpochPerceptron(double **X, double *Y, double *w, int d, int T );
void mixParams(double *w1, double *w2, double *w, int d);

void FileScan(char *, long int *, long int *);





#endif
