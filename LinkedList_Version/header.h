#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h> //getch()




/** value **/

typedef struct STUDENT
{
    char  ID[10];
    float English;
    float Math;
    float Science;
    struct STUDENT *next;
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
void Print (struct STUDENT* head);
void push(struct STUDENT** head_ref);


void initDataSpace (struct STUDENT** head_ref, int number);
float RandomScore ();
void FillOutCSV (FILE *csv, STUDENT *student, int *number);



#endif
