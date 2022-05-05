#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


#define NUM 100

/** value **/

typedef struct STUDENT
{
    char  *ID;
    float English;
    float Math;
    float Science;
}STUDENT;


enum STATE
{
    oneStudent,
    allStudent,
    inquireOneStudent,
    inquireSubjectTOP10,
    inquireScoreTOP10,
    modifyData,
    finish
};


/** function **/
STUDENT *CreateStudentArray (int number);
void RandomID (STUDENT *student, int number);
void RandomScore (STUDENT *student, int number);
void FillOutCSV (FILE *csv, STUDENT *student, int number);
void BubbleSortID (STUDENT *student, int number);
void SwapScore (STUDENT *student, int number1, int number2);
void SwapID (STUDENT *student, int number1, int number2);

int GetCsvLines (FILE *csv);





#endif
