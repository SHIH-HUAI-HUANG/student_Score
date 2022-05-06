#include "header.h"


void PrintfAllStudent (STUDENT *student)
{
    system("cls");
    printf("studentID  English  Math  Science\n");
    for (int i = 0; i < NUM; i++)
    {
        printf("K%s %.3f   %.3f   %.3f\t\n", student[i].ID, student[i].English, student[i].Math, student[i].Science);
    }

    system("pause");
}




//Function : Bubble Sort for string
//Input    : source, numbers of students
//Output   :
void BubbleSortSubject (STUDENT *student, int number)
{
    for (int i = 0; i < (10-1); i++)
    {
        for (int j = (i+1); j < number; j++)
        {
            if ( student[i].English < student[j].English )
            {
                SwapScore (student, i, j);
                SwapID    (student, i, j);
            }
        }
    }
}



void PrintfScoreTOP10 (STUDENT *student)
{
    system("cls");
    printf("English TOP 10 \n");
    for (int i = 0; i < 10; i++)
    {
        printf("number%d = %.3f\n", i+1, student[i].English);
    }
    system("pause");
}




//Function : Bubble Sort for string
//Input    : source, numbers of students
//Output   :
void BubbleSortTotalScore (STUDENT *student, int number)
{
    float student1 = 0;
    float student2 = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = (i+1); j < number; j++)
        {
            student1 = student[i].English + student[i].Math + student[i].Science;
            student2 = student[j].English + student[j].Math + student[j].Science;

            if ( student1 < student2 )
            {
                SwapScore (student, i, j);
                SwapID    (student, i, j);
            }
        }
    }
}


void PrintfStudentTOP10 (STUDENT *student)
{
    system("cls");
    float total = 0;
    printf("Students TOP 10 \n");
    for (int i = 0; i < 10; i++)
    {
        total = student[i].English + student[i].Math + student[i].Science;
        printf("number%d = ", i+1);
        printf("%.3f  ", student[i].English);
        printf("%.3f  ", student[i].Math);
        printf("%.3f  ", student[i].Science);
        printf("%.3f \n ", total);
    }
    system("pause");
}


