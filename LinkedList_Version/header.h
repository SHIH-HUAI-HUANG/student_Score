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

typedef struct DATA
{
    char  ID[10];
    float English;
    float Math;
    float Science;
    struct DATA *next;
} DATA;

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
void FillOutCSV (STUDENT *student, int *number);
void BubbleSortID (STUDENT *student, int number);
void SwapScore (STUDENT *student, int number1, int number2);
void SwapID (STUDENT *student, int number1, int number2);

void End ();
void Menu ();
int GetCsvLines ();

void PrintfAllStudent (struct DATA* head);
void BubbleSortEnglish (STUDENT *student, int number);
void BubbleSortMath (STUDENT *student, int number);
void BubbleSortScience (STUDENT *student, int number);
void PrintEnglishTOP10 (STUDENT *student);
void PrintMathTOP10 (STUDENT *student);
void PrintScienceTOP10 (STUDENT *student);
void RankEnglish (STUDENT *student, int total, int number);
void RankMath (STUDENT *student, int total, int number);
void RankScience (STUDENT *student, int total, int number);
void RankTotalScore (STUDENT *student, int total, int number);
void QuickSort(STUDENT *student, int left,int right);

void BubbleSortTotalScore (STUDENT *student, int number);
void PrintfStudentTOP10 (STUDENT *student);
void OneStudent (STUDENT *student, int number, struct DATA* head);
void PrintfStudentINFO (STUDENT *student, int number);
void PrintTotalScore (STUDENT *student, int number);
STUDENT *DeleteStudent (STUDENT *student, int *number);
void CopyStudent (STUDENT *file1, STUDENT *file2, int number);
STUDENT *InsertStudent (STUDENT *student, int *number);
void PrintSubjectTOP10 (STUDENT *student,int number);


/** color **/
#define KCYN   "\x1B[0;36m"

/** linkedlist **/
void push(struct DATA** head_ref, int number, STUDENT *student);
void InitLinkedlist (struct DATA** head_ref, int number, STUDENT *student);
void Print (struct DATA* head);
void pushOneSpace(struct DATA** head_ref);
void DeleteFinalNode (struct DATA** head_ref, int num);
#endif
