#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define NUM 10

/** function **/
void openCSV (FILE *fp);
void initArray (double *subject);
int* fun ();
void edit(int* address);
void not_array(int* address);

double *CreateDoubleArray1d (int col);
void add (double *input);
void RandomScore (int col, double *src);

/** value **/
typedef struct STUDENT
{
    char   *ID[9];
    double *English;
    double *Math;
    double *Science;
}STUDENT;

#endif
