#include "header.h"

STUDENT *CreateStudentArray (int number)
{
    STUDENT *student = (STUDENT *) calloc(number, sizeof(STUDENT));
    for (int i = 0; i < number; i++)
    {
        student[i].ID = (char *) calloc(10, sizeof(char));
    }
    return student;
}



//Function : assign random number in double Array. (random is 000.000 ~ 1000.000)
//Input    :
//Output   :
void RandomScore (STUDENT *student, int number)
{
    for (int i = 0; i < number; i++)
    {
        student[i].English = rand()%1000 + (rand()%1000+1)*0.001 + 1;
        student[i].Math    = rand()%1000 + (rand()%1000+1)*0.001 + 1;
        student[i].Science = rand()%1000 + (rand()%1000+1)*0.001 + 1;
    }
}



void RandomID (STUDENT *student, int number)
{
    bool repeat = false;
    for (int i = 0; i < number; i++)
    {
        do
        {
            for (int j = 0; j < (10-1); j++)
            {
                student[i].ID[j] = (char)(rand()%10 + 48);
            }
            student[i].ID[10 - 1] = '\0';

            for (int k = 0; k < i; k++)
            {
                if (student[i].ID == student[k].ID) repeat = true;
            }
            //printf("%d", repeat);
        }
        while (repeat);
    }
}



//Function : store the memory of score in file.csv.
//Input    : file.csv, English, Math, Science
//Output   :
void FillOutCSV (FILE *csv, STUDENT *student, int *number)
{
    //csv = fopen("score.csv", "w");
    if( (csv = fopen("score.csv", "w")) == NULL )
    {
        puts("Fail to open file!");
        exit(0);
    }
    fprintf(csv, "StudentID, English, Math, Science\n");
    for (int i = 0; i < *number; i++)
    {
        printf("//////// \n");
        fprintf(csv, "K%s,%.3f,%.3f,%.3f\n",
                student[i].ID,
                student[i].English,
                student[i].Math,
                student[i].Science);
    }
    fclose (csv);
}



//Function : get the lines of file.csv
//Input    : file.csv
//Output   : the number of lines
int GetCsvLines (FILE *csv)
{
    char str[10+1];
    int count = 0;
    if( (csv = fopen("score.csv", "rt")) == NULL )
    {
        puts("Fail to open file!");
        exit(0);
    }

    while(fgets(str, 10, csv) != NULL)
    {
        printf("%s", str);
        count = count + 1;
    }
    fclose(csv);
    return (count/4 - 1);//
}



//Function : Bubble Sort for string
//Input    : source, numbers of students
//Output   :
void BubbleSortID (STUDENT *student, int number)
{
    for (int i = 0; i < (number-1); i++)
    {
        for (int j = (i+1); j < number; j++)
        {
            if ( strcmp (student[i].ID, student[j].ID) > 0 )
            {
                SwapScore (student, i, j);
                SwapID    (student, i, j);
            }
        }
    }
}



//Function : Swap for string
//Input    : source, two numbers you want to change
//Output   :
void SwapID (STUDENT *student, int number1, int number2)
{
    char *temp = (char *) calloc(10, sizeof(char));
    // swap
    temp = student[number1].ID;
    student[number1].ID = student[number2].ID;
    student[number2].ID = temp;
}



//Function : Swap for English, Math, Science
//Input    : source, two numbers you want to change
//Output   :
void SwapScore (STUDENT *student, int number1, int number2)
{
    float temp = 0;
    temp = student[number1].English;
    student[number1].English = student[number2].English;
    student[number2].English = temp;

    temp = student[number1].Math;
    student[number1].Math = student[number2].Math;
    student[number2].Math = temp;

    temp = student[number1].Science;
    student[number1].Science = student[number2].Science;
    student[number2].Science = temp;
}



// change value in function
void test(int *a)
{
    *a = 123546;
}

void test2 (STUDENT *student)
{
    student[0].ID = student[1].ID;
}

/*****************************************************/

/*
//Function :
//Input    : add = 0
//Output   : > return true, < return false
bool NumericComparison (STUDENT student, int row1, int row2, int now)
{
    if       ( student.ID[row1][now] > student.ID[row2][now] ) return true;

    else if ( student.ID[row1][now] < student.ID[row2][now] ) return false;

    else if ( student.ID[row1][now] = student.ID[row2][now] ) return NumericComparison (student, row1, row2, now+1);
}*/


//Function : Memory allocate the double Array.
//Input    : the colum of Array.
//Output   : the address of Array.
double *CreateDoubleArray1d (int col)
{
    double *address = (double *) calloc(col, sizeof(double));
    return address;
}



//Function : Memory allocate
//Input    :
//Output   :
double **CreateCharArray2d (int row, int col)
{
    char **address = (char **) calloc(row, sizeof(char *));
    for (int i = 0; i < row; i++)
    {
        address[i] = (char *) calloc(col, sizeof(char));
    }
    return address;
}

















