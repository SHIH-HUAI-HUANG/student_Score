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
    int studentNum = 10;
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
    BubbleSortID (student, studentNum);
    // Store in file.CSV
    FillOutCSV (csv, student, &studentNum);

    //test (&studentNum);
    //printf("a = %d\n", studentNum);


    system("pause");
    /*************************test**************************/
//printf("num = %lf\n", ceil(10.5)); Gauss function

    //printf("keyboard = ");
    //printf("%c\n", getch() );


    while ( !stop )
    {
        BubbleSortID (student, studentNum);
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
