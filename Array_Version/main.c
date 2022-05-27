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

    student = ChooseDataSource (student, &studentNum);
    system("pause");

    while ( !stop )
    {
        Menu ();
        int stateKey = 0;
        printf("                   state = ");
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
            ChooseSortMode (student, studentNum);
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
