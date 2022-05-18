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
    int studentNum = 0, temp;
    printf("The number of students = ");
    scanf("%d", &studentNum);
    STUDENT *student;
    struct DATA *data = NULL;//linkedlist
    STATE state;
    bool stop = false;
    srand ( time(NULL) );
    clock_t start_t, end_t;
    // Memory allocation
    student = CreateStudentArray (studentNum);
    // Random
    RandomID (student, studentNum);
    RandomScore (student, studentNum);
    QuickSort(student, 0, studentNum-1);
    // Linkedlist
    InitLinkedlist (&data, studentNum, student);


    while ( !stop )
    {
        QuickSort(student, 0, studentNum-1);
        //BubbleSortID (student, studentNum);
        FillOutCSV (student, &studentNum);

        Menu ();
        int stateKey = 0;
        printf("state = ");
        scanf("%d", &stateKey);
        state = stateKey;

        switch (state)
        {
        case allStudent :
            start_t = clock();
            PrintfAllStudent (data);
            end_t = clock();
            printf ("\ntime = %lf s\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
            system("pause");
            break;

        case inquireOneStudent :

            OneStudent (student, studentNum, data);
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
            pushOneSpace (data);
            InitLinkedlist (&data, studentNum, student);
            Print (data);
            system("pause");
            break;

        case deleteData :
            temp = studentNum;
            student = DeleteStudent (student, &studentNum);
            if (temp > studentNum) data = data->next;
            Print (data);
            system("pause");
            break;

        case finish :

            End();
            stop = true;
            break;
        }
    }

    free (student);
    free (data);
    return 0;
}
