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

    char *id;
    while ( !stop )
    {
        BubbleSortID (student, studentNum);
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

            BubbleSortEnglish (student, studentNum);
            PrintEnglishTOP10 (student);
            BubbleSortMath (student, studentNum);
            PrintMathTOP10 (student);
            BubbleSortScience (student, studentNum);
            PrintScienceTOP10 (student);
            break;

        case inquireStudentTOP10 :

            BubbleSortTotalScore (student, studentNum);
            PrintfStudentTOP10 (student);
            break;

        case insertData :


            id = (char *) calloc(10, sizeof(char));
            //id = "123456789";

            //printf("StudentID   = K");
            //scanf("%s", *id);


            //InsertStudent (student, &studentNum);

            studentNum = studentNum + 1;// number of students add 1

            student = (STUDENT *) realloc(student, sizeof(STUDENT) * studentNum );
            student[ studentNum-1 ].ID = (char *) calloc(10, sizeof(char));
            //student[ studentNum-1 ].ID = id;
            for (int j = 0; j < (10-1); j++)
            {
                student[ studentNum-1 ].ID[j] = (char)(rand()%10 + 48);
            }
            student[ studentNum-1 ].English = rand()%1000 + (rand()%1000+1)*0.001 + 1;
            student[ studentNum-1 ].Math    = rand()%1000 + (rand()%1000+1)*0.001 + 1;
            student[ studentNum-1 ].Science = rand()%1000 + (rand()%1000+1)*0.001 + 1;


            FillOutCSV (csv, student, &studentNum);

            system("pause");
            break;

        case deleteData :

            DeleteStudent (student, &studentNum);
            student = (STUDENT *) realloc(student, sizeof(STUDENT) * studentNum );
            FillOutCSV (csv, student, &studentNum);
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
