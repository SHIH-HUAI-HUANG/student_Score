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
        student[i].English = rand()%1000 + (rand()%1000+1)*0.001 ;
        student[i].Math    = rand()%1000 + (rand()%1000+1)*0.001 ;
        student[i].Science = rand()%1000 + (rand()%1000+1)*0.001 ;
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
void FillOutCSV (STUDENT *student, int *number)
{
    FILE *csv;
    if( (csv = fopen("score.csv", "w")) == NULL )
    {
        puts("Fail to open file!");
        exit(0);
    }
    fprintf(csv, "StudentID, English, Math, Science\n");
    for (int i = 0; i < *number; i++)
    {
        fprintf(csv, "K%s,%.3f,%.3f,%.3f\n",
                student[i].ID,
                student[i].English,
                student[i].Math,
                student[i].Science);
    }
    fclose (csv);
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



void QuickSort(STUDENT *student, int first, int last)
{

    int i, j, pivot;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while( !(strcmp(student[i].ID, student[pivot].ID) == 1) && (i<last))
                i++;
            while( strcmp(student[j].ID,student[pivot].ID) == 1 )
                j--;
            if(i<j)
            {
                SwapID (student, i, j);
                SwapScore (student, i, j);
            }
        }
        SwapID (student, pivot, j);
        SwapScore (student, pivot, j);
        QuickSort(student, first, j-1);
        QuickSort(student, j+1, last);
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



//Function : get the lines of file.csv
//Input    : file.csv
//Output   : the number of lines
int GetCsvLines (char file_name[])
{
    FILE *csv;
    char str[10+1];
    int count = 0;
    if( (csv = fopen(file_name, "r")) == NULL )
    {
        puts("Fail to open file!");
        exit(0);
    }

    while(fgets(str, 10, csv) != NULL)
    {
       // printf("%s", str);
        count = count + 1;
    }
    fclose(csv);
    return (count/4 - 1);//
}



void ReadCSV (STUDENT *student, char file_name[])
{
    //file_name = "score.csv";
    FILE *fp;
    fp = fopen(file_name, "r");

    if (!fp)
    {
        fprintf(stderr, "failed to open file for reading\n");
        return 1;
    }

    char line[50];
    char *result = NULL;
    fgets(line, 50, fp);
    int i = 0;

    while(fgets(line, 50, fp) != NULL)
    {

        result = strtok(line, "K,");
        int j = 0;
        while( result != NULL )
        {
            switch (j)
            {
            case 0:
               sscanf(result, "%s", student[i].ID);
                break;
            case 1:
                student[i].English = atof(result);

                break;
            case 2:
                student[i].Math = atof(result);

                break;
            case 3:
                student[i].Science = atof(result);

                break;
            }
            result = strtok(NULL, ",");
            j++;
        }
        printf("\n");
        i++;
    }

    fclose (fp);

}










