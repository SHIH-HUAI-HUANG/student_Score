#include "header.h"


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

//Function : assign random number in double Array. (random is 000.000 ~ 1000.000)
//Input    :
//Output   :
void RandomScore (int col, double *src)
{
    for (int i = 0; i < col; i++)
    {
        src[i] = rand()%1000 + (rand()%1000+1)*0.001 + 1;
    }
}



//Function : assign random number
//Input    :
//Output   :
void RandomStudentID (int row, int col, char **src)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < (col-1); j++)
        {
           src[i][j] = (char)(rand()%10 + 48);
        }
        src[i][col - 1] = '\0';
    }
}



//Function : store the memory of score in .csv file.
//Input    : csv file, English, Math, Science
//Output   :
void FillOutCSV (FILE *csv,int col, double *subject1, double *subject2, double *subject3, char **student)
{
    csv = fopen("score.csv", "w");
    fprintf(csv, "StudentID, English, Math, Science\n");
    for (int i = 0; i < col; i++)
    {
        fprintf(csv, "K%s,%.3f,%.3f,%.3f\n", student[i], subject1[i], subject2[i], subject3[i]);
    }
    fclose (csv);
    return 0;
}


//for example
void add (double *input)
{
    input[0] = input[0] + 87;
}



