/*****************************************/
/**                                      */
/**  Project : DataStructure Homework-1  */
/**  Author  : Shih-Huai Huang           */
/**  ID      : B1085154                  */
/**                                      */
/*****************************************/

#include "header.h"

int main(int argc, char **argv)
{
    // define value
    int studentNum = 0;
    printf("The number of students = ");
    scanf("%d", &studentNum);
    STUDENT *student;
    STATE state;
    FILE *csv;
    bool stop = false;
    srand ( time(NULL) );
    // Memory allocation
    student = CreateStudentArray (studentNum);
    // Random
    RandomID (student, studentNum);
    RandomScore (student, studentNum);

    while ( !stop )
    {
        QuickSort(student, 0, studentNum-1);
        //BubbleSortID (student, studentNum);
        FillOutCSV (csv, student, &studentNum);

        Menu ();
        int stateKey = 0;
        printf("state = ");
        scanf("%d", &stateKey);
        state = stateKey;

        switch (state)
        {
        case allStudent :

            PrintfAllStudent (student, studentNum);

            break;

        case inquireOneStudent :

            OneStudent (student, studentNum);
            break;

        case inquireSubjectTOP10 :

            PrintSubjectTOP10 (student, studentNum);

            break;

        case inquireStudentTOP10 :

            BubbleSortTotalScore (student, studentNum);
            PrintfStudentTOP10 (student);
            break;

        case insertData :

            student = InsertStudent (student, &studentNum);

            break;

        case deleteData :

            student = DeleteStudent (student, &studentNum);

            break;

        case finish :

            End();
            stop = true;
            break;
        }
    }

    free (student);
    return 0;
}
