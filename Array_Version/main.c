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
    STATE state;
    FILE *csv;
    bool stop = false;
    srand ( time(NULL) );
    // Memory allocation
    student = CreateStudentArray(NUM);//test
    // Random
    RandomID (student, NUM);
    RandomScore (student, NUM);
    BubbleSortID (student, NUM);
    // Store in file.CSV
    FillOutCSV (csv, student, NUM);


    system("pause");
    /*************************test**************************/
//printf("num = %lf\n", ceil(10.5)); Gauss function

    //printf("keyboard = ");
    //printf("%c\n", getch() );

    while ( !stop )
    {
        BubbleSortID (student, NUM);
        Menu ();
        int stateKey = 0;
        printf("state = ");
        scanf("%d", &stateKey);
        state = stateKey;

        switch (state)
        {
        case oneStudent :
            printf("1\n");
            system("pause");

            break;

        case allStudent :
            PrintfAllStudent (student);

            break;

        case inquireOneStudent :
            printf("3\n");
            system("pause");

            break;

        case inquireSubjectTOP10 :
            BubbleSortSubject (student, NUM);
            PrintfScoreTOP10(student);

            break;

        case inquireStudentTOP10 :
            BubbleSortTotalScore (student, NUM);
            PrintfStudentTOP10 (student);
            break;

        case modifyData :
            printf("6\n");
            system("pause");

            break;

        case finish :
            End();
            system("pause");
            stop = true;
            break;

        }

    }

    /*******************************************************/

    free (student);
    //system("pause");
    //system("cls");

    return 0;
}
