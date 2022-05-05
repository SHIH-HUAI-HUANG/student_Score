/*****************************************/
/**                                      */
/**  Project : DataStructure Homework-1  */
/**  Author  : Shih-Huai Huang           */
/**  ID      : B1085154                  */
/**                                      */
/*****************************************/

#include "header.h"

int main()
{
    // define value
    STUDENT student;
    FILE *csv;
    srand ( time(NULL) );
    // Memory allocation
    student.English = CreateDoubleArray1d (NUM);
    student.Math    = CreateDoubleArray1d (NUM);
    student.Science = CreateDoubleArray1d (NUM);
    student.ID      = CreateCharArray2d (NUM, 10);
    //student = CallocStudent (student, NUM);
    // Random
    RandomScore (NUM, student.English);
    RandomScore (NUM, student.Math);
    RandomScore (NUM, student.Science);
    RandomStudentID (NUM, 10, student.ID);
    //RandomStudent (student, NUM);
    // Store in file.CSV

    BubbleSortID (student.ID, NUM);

    FillOutCSV (csv, NUM, student);


    /*************************test**************************/

    //printf("num = %lf\n", ceil(10.5)); Gauss function




    /*******************************************************/
    //printf ("lines = %d\n", GetCsvLines (csv) );
    free (student.English);
    free (student.Math);
    free (student.Science);
    free (student.ID);
    system("pause");
    system("cls");
    printf("Hello world!\n");
    return 0;
}
