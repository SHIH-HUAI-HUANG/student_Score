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
    STUDENT *student;
    STATE state;
    bool stop = false;
    srand ( time(NULL) );
    clock_t start_t, end_t;
    /******************************************************/
    int line = 1;
    int key = 0;
    while (key != 13)
    {
        if (key == 80) line++; //down-key
        else if (key == 72)line--; //up-key
        if (line < 1) line = 1;
        else if (line > 2) line = 2;
        switch (line)
        {
        case 1:
            system("cls");
            printf("\n\n\n\n\n\n\n                   Choose your source\n\n");
            printf("                   --> Read exist file     \n");
            printf("                       Random from computer\n");
            break;
        case 2:
            system("cls");
            printf("\n\n\n\n\n\n\n                   Choose your source\n\n");
            printf("                       Read exist file     \n");
            printf("                   --> Random from computer\n");
            break;
        }
        key = getch();
    }

    switch (line)
    {
    case 1:

        studentNum =  GetCsvLines("score.csv");
        student = CreateStudentArray (studentNum);
        ReadCSV (student, "score.csv");
        break;

    case 2:
        printf("\n\n\n\n\n\n\n\n\n\n                 The number of students = ");
        scanf("%d", &studentNum);
        // Memory allocation
        student = CreateStudentArray (studentNum);
        // Random
        RandomID (student, studentNum);
        RandomScore (student, studentNum);
       // FillOutCSV (student, &studentNum);
        break;
    }

    /******************************************************/




    while ( !stop )
    {
        Menu ();
        int stateKey = 0;
        printf("state = ");
        scanf("%d", &stateKey);
        state = stateKey;

        switch (state)
        {
        case allStudent :
            start_t = clock();
            PrintfAllStudent (student, studentNum);
            end_t = clock();
            printf ("\ntime = %lf s\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
            system("pause");
            break;

        case inquireOneStudent :
            OneStudent (student, studentNum);
            system("pause");
            break;

        case inquireSubjectTOP10 :
            start_t = clock();
            PrintSubjectTOP10 (student, studentNum);
            end_t = clock();
            printf ("\ntime = %lf s\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
            system("pause");
            break;

        case inquireStudentTOP10 :
            start_t = clock();
            BubbleSortTotalScore (student, studentNum);
            PrintfStudentTOP10 (student);
            end_t = clock();
            printf ("\ntime = %lf s\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
            system("pause");
            break;

        case insertData :
            student = InsertStudent (student, &studentNum);
            system("pause");
            break;

        case deleteData :
            student = DeleteStudent (student, &studentNum);
            system("pause");
            break;

        case SORT :
            start_t = clock();
            ChooseSortMode (student, studentNum);
            end_t = clock();
            printf ("\ntime = %lf s\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
            system("pause");
            break;

        case finish :
            FillOutCSV (student, &studentNum);
            End();
            stop = true;
            break;
        }
    }

    free (student);
    return 0;
}
