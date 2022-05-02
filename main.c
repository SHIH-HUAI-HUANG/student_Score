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
    FILE *fp;
    srand ( time(NULL) );
    // Memory allocation
    student.English = CreateDoubleArray1d (NUM);
    student.Math    = CreateDoubleArray1d (NUM);
    student.Science = CreateDoubleArray1d (NUM);
    // Random
    RandomScore (NUM, student.English);
    RandomScore (NUM, student.Math);
    RandomScore (NUM, student.Science);

    //print for test
    for (int i = 0; i < 10; i++)
    {
        printf("**************Eng = %.3f, Math = %.3f, Sci = %.3f\t\n", student.English[i], student.Math[i], student.Science[i]);
    }

    FillOutCSV (fp, NUM, (student.English), (student.Math), (student.Science));



    system("pause");
    system("cls");
    printf("Hello world!\n");
    return 0;
}
