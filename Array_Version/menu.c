#include "header.h"

//Function : Print all students' IDs and Scores.
//Input    : student's information, numbers of students
//Output   :
void PrintfAllStudent (STUDENT *student, int number)
{
    system("cls");
    printf("studentID  English  Math  Science\n");
    for (int i = 0; i < number; i++)
    {
        printf("K%s %.3f   %.3f   %.3f\t\n", student[i].ID, student[i].English, student[i].Math, student[i].Science);
    }
}




//Function : Bubble Sort for English, but only TOP-10.
//Input    : student's information, numbers of students
//Output   :
void BubbleSortEnglish (STUDENT *student, int number)
{
    for (int i = 0; i < 10; i++)
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



//Function : Bubble Sort for Math, but only TOP-10.
//Input    : student's information, numbers of students
//Output   :
void BubbleSortMath (STUDENT *student, int number)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = (i+1); j < number; j++)
        {
            if ( student[i].Math < student[j].Math )
            {
                SwapScore (student, i, j);
                SwapID    (student, i, j);
            }
        }
    }
}



//Function : Bubble Sort for Science, but only TOP-10.
//Input    : student's information, numbers of students
//Output   :
void BubbleSortScience (STUDENT *student, int number)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = (i+1); j < number; j++)
        {
            if ( student[i].Science < student[j].Science )
            {
                SwapScore (student, i, j);
                SwapID    (student, i, j);
            }
        }
    }
}



void PrintEnglishTOP10 (STUDENT *student)
{
    system("cls");
    printf("English TOP 10 \n");
    for (int i = 0; i < 10; i++)
    {
        printf("number%d ( K%s ) = %.3f\n", i+1, student[i].ID, student[i].English);
    }
}



void PrintMathTOP10 (STUDENT *student)
{
    printf("\nMath TOP 10 \n");
    for (int i = 0; i < 10; i++)
    {
        printf("number%d ( K%s ) = %.3f\n", i+1, student[i].ID, student[i].Math);
    }
}



void PrintScienceTOP10 (STUDENT *student)
{
    printf("\nScience TOP 10 \n");
    for (int i = 0; i < 10; i++)
    {
        printf("number%d ( K%s ) = %.3f\n", i+1, student[i].ID, student[i].Science);
    }

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
    printf("number    StudentID  English  Math    Science   TotalScore\t\n");
    for (int i = 0; i < 10; i++)
    {
        total = student[i].English + student[i].Math + student[i].Science;
        printf("number%d = ", i+1);
        printf("%s  ", student[i].ID);
        printf("%.3f  ", student[i].English);
        printf("%.3f  ", student[i].Math);
        printf("%.3f  ", student[i].Science);
        printf("%.3f \n ", total);
    }
}



void OneStudent (STUDENT *student, int number)
{
    system("cls");
    char id[10];
    id[9] = '\0';
    printf("StudentID   = K");
    scanf("%s", &id);

    clock_t start_t, end_t;
    start_t = clock();
    int i = -1;
    bool same = false;
    // check
    while ( !same )
    {
        i++;
        if (i == number)
        {
            printf("The StudentID is not exist !\n");
            same = true;
        }
        else
        {
            if( strcmp(id, student[i].ID) == 0 ) same = true;
        }
    }
    // printf
    if (i != number)
    {
        PrintfStudentINFO (student, i);
        RankEnglish (student, number, i);
        RankMath (student, number, i);
        RankScience (student, number, i);
        RankTotalScore (student, number, i);
    }
    end_t = clock();
    printf ("\ntime = %lf s\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);

}

void PrintfStudentINFO (STUDENT *student, int number)
{
    printf("StudentID   = K%s \n\n", student[number].ID);
    printf("English     = %.3f \n", student[number].English);
    printf("Math        = %.3f \n", student[number].Math);
    printf("Science     = %.3f \n", student[number].Science);
    PrintTotalScore (student, number);
}


void PrintTotalScore (STUDENT *student, int number)
{
    float total = student[number].English + student[number].Math + student[number].Science;
    printf("Total Score = %.3f \n", total);
}


STUDENT *InsertStudent (STUDENT *student, int *number)
{
    system("cls");
    clock_t start_t, end_t;
    char *id;
    id = (char *) calloc(10, sizeof(char));
    float Eng, Math, Sci;
    bool repeat = false;

    do
    {
        printf("StudentID   = K");
        scanf("%s", id);
    }
    while (strlen(id) != 9);

    for (int i = 0; i < *number; i++)
    {
        if ( strcmp(id, student[i].ID) == 0 ) repeat = true;
    }

    if (repeat)
    {
        printf("The StudentID is not exist !\n");
    }
    else
    {
        do
        {
            printf("English =");
            scanf("%f", &Eng);
        }
        while (Eng<0.000 || Eng>1000.000);
        do
        {
            printf("Math = ");
            scanf("%f", &Math);
        }
        while (Math<0.000 || Math>1000.000);
        do
        {
            printf("Science = ");
            scanf("%f", &Sci);
        }
        while (Sci<0.000 || Sci>1000.000);
        start_t = clock();
        *number = *number + 1;// number of students add 1

        student = (STUDENT *) realloc(student, sizeof(STUDENT) * (*number) );
        student[ *number-1 ].ID = (char *) calloc(10, sizeof(char));

        student[ *number - 1].ID = id;
        student[ *number-1 ].English = Eng;
        student[ *number-1 ].Math    = Math;
        student[ *number-1 ].Science = Sci;
        printf ("The number of students is %d\n", *number);
    }

    end_t = clock();
    printf ("\ntime = %lf s\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
    return student;
}



//Function : Delete one student's information about ID and score.
//Input    :
//Output   :
STUDENT *DeleteStudent (STUDENT *student, int *number)
{
    system("cls");
    clock_t start_t, end_t;
    char id[10];
    id[9] = '\0';
    printf("StudentID   = K");
    scanf("%s", &id);

    start_t = clock();
    int i = -1;
    bool stop = false, same = false;
    // check
    while ( !stop )
    {
        i++;
        if (i == *number)
        {
            printf("The StudentID is not exist !\n");
            stop = true;
        }
        else
        {
            if( strcmp(id, student[i].ID) == 0 )
            {
                stop = true;
                same = true;
            }
        }
    }

    for (int j = i; j < (*number-1); j++)
    {
        student[j].ID      = student[j+1].ID;
        student[j].English = student[j+1].English;
        student[j].Math    = student[j+1].Math;
        student[j].Science = student[j+1].Science;
    }
    if (same)
    {
        *number = *number - 1;// number of students minus 1
        student = (STUDENT *) realloc(student, sizeof(STUDENT) * (*number) );
    }

    printf ("The number of students is %d\n", *number);
    end_t = clock();
    printf ("\ntime = %lf s\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
    return student;
}



//Function : Copy student's information from file2 to file1.
//Input    :
//Output   :
void CopyStudent (STUDENT *file1, STUDENT *file2, int number)
{
    for (int i = 0; i < number; i++)
    {
        file1[i].ID      = file2[i].ID;
        file1[i].English = file2[i].English;
        file1[i].Math    = file2[i].Math;
        file1[i].Science = file2[i].Science;
    }

}


void RankEnglish (STUDENT *student, int total, int number)
{
    int place = 1;
    for (int i = 0; i < total; i++)
    {
        if (student[number].English < student[i].English) place = place + 1;
    }
    printf ("The English place is : %d\n", place);
}


void RankMath (STUDENT *student, int total, int number)
{
    int place = 1;
    for (int i = 0; i < total; i++)
    {
        if (student[number].Math < student[i].Math) place = place + 1;
    }
    printf ("The Math    place is : %d\n", place);
}



void RankScience (STUDENT *student, int total, int number)
{
    int place = 1;
    for (int i = 0; i < total; i++)
    {
        if (student[number].Science < student[i].Science) place = place + 1;
    }
    printf ("The Science place is : %d\n", place);
}


void RankTotalScore (STUDENT *student, int total, int number)
{
    int place = 1;
    float totalscore1 = student[number].English + student[number].Math + student[number].Science;
    for (int i = 0; i < total; i++)
    {
        float totalscore2 = student[i].English + student[i].Math + student[i].Science;
        if (totalscore1 < totalscore2) place = place + 1;
    }
    printf ("The student rank is  : %d\n", place);
}


void PrintSubjectTOP10 (STUDENT *student,int number)
{
    BubbleSortEnglish (student, number);
    PrintEnglishTOP10 (student);
    BubbleSortMath (student, number);
    PrintMathTOP10 (student);
    BubbleSortScience (student, number);
    PrintScienceTOP10 (student);
}


void ChooseSortMode (STUDENT *student, int number)
{
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
            printf("\n\n\n\n\n\n\n                   Choose your mode\n\n");
            printf("                   --> Bubble Sort \n");
            printf("                       Quick  Sort \n");
            break;
        case 2:
            system("cls");
            printf("\n\n\n\n\n\n\n                   Choose your mode\n\n");
            printf("                       Bubble Sort \n");
            printf("                   --> Quick  Sort \n");
            break;
        }
        key = getch();
    }

    switch (line)
    {
    case 1:
        BubbleSortID (student, number);
        break;

    case 2:
        QuickSort(student, 0, number-1);
        break;
    }
    system("cls");
    printf("\n\n\n\n\n\n\n                  Sort is finished !\n\n\n\n\n");
}
