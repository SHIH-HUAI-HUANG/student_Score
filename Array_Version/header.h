#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h> //getch()


#define NUM 10

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
    allStudent          = 1,
    inquireOneStudent   = 2,
    inquireSubjectTOP10 = 3,
    inquireStudentTOP10 = 4,
    insertData          = 5,
    deleteData          = 6,
    finish              = 7
} STATE;


/** function **/
STUDENT *CreateStudentArray (int number);
void RandomID (STUDENT *student, int number);
void RandomScore (STUDENT *student, int number);
void FillOutCSV (FILE *csv, STUDENT *student, int *number);
void BubbleSortID (STUDENT *student, int number);
void SwapScore (STUDENT *student, int number1, int number2);
void SwapID (STUDENT *student, int number1, int number2);

void End ();
void Menu ();

int GetCsvLines (FILE *csv);

void PrintfAllStudent (STUDENT *student, int number);
void BubbleSortEnglish (STUDENT *student, int number);
void BubbleSortMath (STUDENT *student, int number);
void BubbleSortScience (STUDENT *student, int number);
void PrintEnglishTOP10 (STUDENT *student);
void PrintMathTOP10 (STUDENT *student);
void PrintScienceTOP10 (STUDENT *student);


void BubbleSortTotalScore (STUDENT *student, int number);
void PrintfStudentTOP10 (STUDENT *student);
void OneStudent (STUDENT *student, int number);
void PrintfStudentINFO (STUDENT *student, int number);
void PrintTotalScore (STUDENT *student, int number);
void DeleteStudent (STUDENT *student, int *number);
void CopyStudent (STUDENT *file1, STUDENT *file2, int number);
void InsertStudent (STUDENT *student, int *number);

void test(int *a);
void test2 (STUDENT *student);


#endif
