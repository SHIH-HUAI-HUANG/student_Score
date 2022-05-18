#include "header.h"


/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new STUDENT on the front of the list. */
void push(struct DATA** head_ref, int number, STUDENT *student)
{
    /* 1. allocate STUDENT */
    struct DATA* new_STUDENT = (struct DATA*) calloc(1, sizeof(struct DATA));

    /* 2. put in the data */
    new_STUDENT->English = student[number].English;
    new_STUDENT->Math    = student[number].Math;
    new_STUDENT->Science = student[number].Science;
    for (int i = 0; i < 10; i++)
    {
        new_STUDENT->ID[i] = student[number].ID[i];
    }

    /* 3. Make next of new STUDENT as head */
    new_STUDENT->next = (*head_ref);

    /* 4. move the head to point to the new STUDENT */
    (*head_ref) = new_STUDENT;
}

void InitLinkedlist (struct DATA** head_ref, int number, STUDENT *student)
{
    int num = -1;
    for (int i = 0; i < number; i++)
    {
        num = num + 1;
        push (head_ref, num, student);
    }

}

void Print (struct DATA* head)
{
    while (head != NULL)
    {
        printf("%.3f\n", head->English);
        printf("%.3f\n", head->Math   );
        printf("%.3f\n", head->Science);
        printf("K%s\n", head->ID);

        head = head->next;
    }
}

void pushOneSpace(struct DATA** head_ref)
{
    struct DATA* new_STUDENT = (struct DATA*) calloc(1, sizeof(struct DATA));
    new_STUDENT->next = (*head_ref);
    (*head_ref) = new_STUDENT;
}





