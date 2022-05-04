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
            printf("id = %s\n", src[i]);
            for (int k = 0; k < i; k++)
            {
                if (src[i] == src[k]) repeat = true;
            }
            //printf("%d", repeat);
        }
        while (repeat);
    }
}



//Function : store the memory of score in .csv file.
//Input    : file.csv, English, Math, Science
//Output   :
void FillOutCSV (FILE *csv,int col, double *subject1, double *subject2, double *subject3, char **student)
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



//Function : store the memory of score in .csv file.
//Input    : csv file, English, Math, Science
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
//Output   :
bool BoysGameString (int row1,int row2, char **src, int add)
{
    if       ( src[row1][add] > src[row2][add] ) return true;

    else if ( src[row1][add] < src[row2][add] ) return false;

    else if ( src[row1][add] = src[row2][add] ) BoysGameString (row1, row2, **src, add+1);
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



//Function : get the lines of file.csv
//Input    : file.csv
//Output   : the number of lines
void QuickSort (int left,int right, char **src)
{
 if(left < right) {
        int s = number[(left+right)/2];
        int i = left - 1;
        int j = right + 1;

        while(1) {
            while(number[++i] < s) ;  // 向右找
            while(number[--j] > s) ;  // 向左找
            if(i >= j)
                break;
            SWAP(number[i], number[j]);
        }

        quickSort(number, left, i-1);   // 對左邊進行遞迴
        quickSort(number, j+1, right);  // 對右邊進行遞迴
    }

}






