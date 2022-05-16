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
    struct STUDENT *student = NULL;
    FILE *csv;
    srand ( time(NULL) );
    int num = 5;

    initDataSpace (&student, num);
    Print(student);
    Print(student);
    FillOutCSV (csv, student, &num);
    printf ("\n%.3f\n", student->next->English);
    printf("Hello world!\n");
    return 0;
}
