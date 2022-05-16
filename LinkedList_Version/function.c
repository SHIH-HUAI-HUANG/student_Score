#include "header.h"

void Print (struct STUDENT* head)
{
    while (head != NULL)
    {
        printf("%.3f\n", head->English);
        printf("%.3f\n", head->Math   );
        printf("%.3f\n\n", head->Science);


        head = head->next;
    }
}




/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new STUDENT on the front of the list. */
void pushEnglish(struct STUDENT** head_ref)
{
    /* 1. allocate STUDENT */
    struct STUDENT* new_STUDENT = (struct STUDENT*) calloc(1, sizeof(struct STUDENT));

    /* 2. put in the data */
    new_STUDENT->English = RandomScore();
    new_STUDENT->Math    = RandomScore();
    new_STUDENT->Science = RandomScore();
    //new_STUDENT->ID      =

    /* 3. Make next of new STUDENT as head */
    new_STUDENT->next = (*head_ref);

    /* 4. move the head to point to the new STUDENT */
    (*head_ref) = new_STUDENT;
}


void initDataSpace (struct STUDENT** head_ref, int number)
{
    for (int i = 0; i < number; i++)
    {
        pushEnglish (head_ref);
    }

}



float RandomScore ()
{
    float score = rand()%1000 + (rand()%1000+1)*0.001;
    return score;
}


//Function : store the memory of score in file.csv.
//Input    : file.csv, English, Math, Science
//Output   :
void FillOutCSV (FILE *csv, STUDENT *student, int *number)
{
    if( (csv = fopen("score.csv", "w")) == NULL )
    {
        puts("Fail to open file!");
        exit(0);
    }
    fprintf(csv, "StudentID, English, Math, Science\n");
    for (int i = 0; i < *number; i++)
    {
        fprintf(csv, " ,%.3f,%.3f,%.3f\n",student->English,
                student->Math,
                student->Science);
        student = student->next;
    }
    fclose (csv);
}


void RandomID (STUDENT *student, int number)
{
    bool repeat = false;
    for (int i = 0; i < number; i++)
    {
        do
        {
            for (int j = 0; j < (10-1); j++)
            {
                student[i].ID[j] = (char)(rand()%10 + 48);
            }
            student[i].ID[10 - 1] = '\0';

            for (int k = 0; k < i; k++)
            {
                if (student[i].ID == student[k].ID) repeat = true;
            }
            //printf("%d", repeat);
        }
        while (repeat);
    }
}
