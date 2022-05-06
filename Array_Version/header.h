#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h> //getch()


#define NUM 100

/** value **/

typedef struct STUDENT
{
    char  *ID;
    float English;
    float Math;
    float Science;
} STUDENT;


typedef enum STATE
{
    oneStudent          = 1,
    allStudent          = 2,
    inquireOneStudent   = 3,
    inquireSubjectTOP10 = 4,
    inquireStudentTOP10 = 5,
    modifyData          = 6,
    finish              = 7
} STATE;


/** function **/
STUDENT *CreateStudentArray (int number);
void RandomID (STUDENT *student, int number);
void RandomScore (STUDENT *student, int number);
void FillOutCSV (FILE *csv, STUDENT *student, int number);
void BubbleSortID (STUDENT *student, int number);
void SwapScore (STUDENT *student, int number1, int number2);
void SwapID (STUDENT *student, int number1, int number2);

void End ();
void Menu ();

int GetCsvLines (FILE *csv);

void PrintfAllStudent (STUDENT *student);
void BubbleSortSubject (STUDENT *student, int number);
void PrintfScoreTOP10 (STUDENT *student);
void BubbleSortTotalScore (STUDENT *student, int number);
void PrintfStudentTOP10 (STUDENT *student);

#endif
