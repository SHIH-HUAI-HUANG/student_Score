#include "header.h"

//Function : Open the .scv file
//Input    : file's name
//Output   :
void openCSV (FILE *fp)
{
    fp = fopen("score.csv", "w");
    char line[20];
    char *result = NULL;
    fprintf (fp, "hello,123,456,789\n");
    fprintf (fp, "andy,13,56,79\n");
    fprintf (fp, "%s,%s,%s,%s", "Ling", "84", "345", "24");
    while(fgets(line, 20, fp) != NULL)
    {
        result = strtok(line, ",");
        int i = 0;
        while( result != NULL )
        {
            if(i!=0)
            {
                printf("%d\t", atoi(result));
            }
            else
            {
                printf("%s\t", result);
                i++;
            }
            result = strtok(NULL, ",");
        }
        printf("\n");
    }
    fclose (fp);
    return 0;
}

//Function :
//Input    :
//Output   :
void initArray (double *subject)
{
    subject = calloc (NUM, sizeof(double));


    for (int i = 0; i < NUM; i++)
    {
        subject[i] = rand()%1000 + (rand()%1000+1)*0.001;
        printf("%.3f\n", subject[i]);
    }
}

int* fun ()
{
    int *p;
    p = calloc (5, sizeof(int));
    *p = 8787;
    return p;
}

void edit(int* address)
{
    address[2]=69420;
    address[3]=42069;
}

void not_array(int* address)
{
    *address=5678;
}

//Function :
//Input    :
//Output   :
double *CreateDoubleArray1d (int col)
{
    double *address = (double *) calloc(col, sizeof(double));
    return address;
}

void add (double *input)
{
    input[0] = input[0] + 87;
}

//Function :
//Input    :
//Output   :
void RandomScore (int col, double *src)
{
    for (int i = 0; i < col; i++)
    {
      src[i] = rand()%1000 + (rand()%1000+1)*0.001;
    }
}










