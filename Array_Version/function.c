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



//Function : Memory allocate
//Input    :
//Output   :
STUDENT CallocStudent (STUDENT student, int number)
{
    student.English = CreateDoubleArray1d (number);
    student.Math    = CreateDoubleArray1d (number);
    student.Science = CreateDoubleArray1d (number);
    student.ID      = CreateCharArray2d (number, 10);
    return student;
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



//Function : assign random number for student ID.
//           No repeation of number.
//Input    :
//Output   :
void RandomStudentID (int row, int col, char **src)
{
    bool repeat = false;
    for (int i = 0; i < row; i++)
    {
        do
        {
            for (int j = 0; j < (col-1); j++)
            {
                src[i][j] = (char)(rand()%10 + 48);
            }
            src[i][col - 1] = '\0';
            //printf("id = %s\n", src[i]);
            for (int k = 0; k < i; k++)
            {
                if (src[i] == src[k]) repeat = true;
            }
            //printf("%d", repeat);
        }
        while (repeat);
    }
}



//Function : Memory allocate
//Input    :
//Output   :
void RandomStudent (STUDENT student, int number)
{

    RandomScore (number, student.English);
    RandomScore (number, student.Math);
    RandomScore (number, student.Science);
    RandomStudentID (number, 10, student.ID);

}



//Function : store the memory of score in .csv file.
//Input    : file.csv, English, Math, Science
//Output   :
void FillOutCSV (FILE *csv,int col, STUDENT student)
{
    //csv = fopen("score.csv", "w");
    if( (csv = fopen("score.csv", "w")) == NULL )
    {
        puts("Fail to open file!");
        exit(0);
    }
    fprintf(csv, "StudentID, English, Math, Science\n");
    for (int i = 0; i < col; i++)
    {
        fprintf(csv, "K%s,%.3f,%.3f,%.3f\n", student.ID[i], student.English[i], student.Math[i], student.Science[i]);
    }
    fclose (csv);
    return 0;
}


//for example
void add (double *input)
{
    input[0] = input[0] + 87;
}



//Function :
//Input    :
//Output   :
void Swap (double *num1, double *num2)
{
    double temp = 0;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}



//Function :
//Input    : add = 0
//Output   : > return true, < return false
bool NumericComparison (int row1,int row2, char **src, int add)
{
    if       ( src[row1][add] > src[row2][add] ) return true;

    else if ( src[row1][add] < src[row2][add] ) return false;

    else if ( src[row1][add] = src[row2][add] ) return NumericComparison (row1, row2, src, add+1);
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
void BubbleSortID (char **src, int number)
{
    for (int i = 0; i < (number-1); i++)
    {
        for (int j = (i+1); j < number; j++)
        {
            if ( NumericComparison (i, j, src, 0) )
            {
                SwapID (src, i, j);
            }
        }
    }

}



//Function : Swap for string
//Input    : source, two numbers you want to change
//Output   :
void SwapID (char **src, int number1, int number2)
{
    char **temp = (char **) calloc(1, sizeof(char *));
    temp[0] = (char *) calloc(10, sizeof(char));

    temp[0]      = src[number1];
    src[number1] = src[number2];
    src[number2] = temp[0];
}
