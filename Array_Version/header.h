#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define NUM 10

/** value **/

typedef struct STUDENT
{
    char   **ID;
    double *English;
    double *Math;
    double *Science;
}STUDENT;


/** function **/

double *CreateDoubleArray1d (int col);
double **CreateCharArray2d (int row, int col);
void add (double *input);
void RandomScore (int col, double *src);
void RandomStudentID (int row, int col, char **src);
void FillOutCSV (FILE *csv,int col, double *subject1, double *subject2, double *subject3, char **student);



#endif
