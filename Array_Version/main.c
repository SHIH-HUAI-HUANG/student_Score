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
    STUDENT *student;//test
    FILE *csv;
    srand ( time(NULL) );
    // Memory allocation
    student = CreateStudentArray(NUM);//test
    // Random
    RandomID (student, NUM);
    RandomScore (student, NUM);
    // Store in file.CSV
    BubbleSortID (student, NUM);
    FillOutCSV (csv, student, NUM);



    /*************************test**************************/

    //printf("num = %lf\n", ceil(10.5)); Gauss function



    /*******************************************************/

    free (student);
    //system("pause");
    //system("cls");
    printf("Hello world!\n");
    return 0;
}
