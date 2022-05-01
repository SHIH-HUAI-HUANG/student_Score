/****************************************/
/**                                    **/
/** Project : DataStructure Homework-1 **/
/** Author  : Shih-Huai Huang          **/
/** ID      : B1085154                 **/
/**                                    **/
/****************************************/

#include "header.h"

int main()
{
    //define value
    struct STUDENT student;
    srand ( time(NULL) );
    //空間配置
    student.English = CreateDoubleArray1d (NUM);
    student.Math    = CreateDoubleArray1d (NUM);
    student.Science = CreateDoubleArray1d (NUM);
    //亂數配置
    RandomScore (NUM, student.English);
    RandomScore (NUM, student.Math);
    RandomScore (NUM, student.Science);

    //print for test
    for (int i = 0; i < 10; i++)
    {
        printf("**************Eng = %.3f, Math = %.3f, Sci = %.3f\t\n", student.English[i], student.Math[i], student.Science[i]);
    }



//***************************
    int *n=fun();
    edit(n);
    printf("%d, %d\n", n[2], n[3]);

    int num=1069;
    int *num_ptr=&num;
    not_array(num_ptr);
    printf("confused????%d\n",*num_ptr);


    //n=fun ();

    printf("%d, %d, %x\n", n, *n, &n);

    free(n);

    // printf ("num = ");
    //scanf("%d", &a);
    //printf ("%d", a);
    double r = 952.487;
    char text[20];
    sprintf(text, "%.3f", r);// double 轉 string 以便寫入.csv檔
    //itoa(r, text,10);
    printf ("%s\n", text);


    //initArray (& student.English);


    for (int i = 0; i < 5; i++)
    {
        printf("k%c%c%c\n", (char)(rand()%10 + 48), (char)(rand()%10 + 48), (char)(rand()%10 + 48) );//
    }


    printf ("///////ans1 = %.3f \n", rand()%1000 + (rand()%1000+1)*0.001 );//score

    system("pause");
    FILE *fp;
    openCSV (fp);

    /***********************************************/
    int *dynArr;
    // 指定空間大小
    int arrLen1 = 10;
    int arrLen2 = 5;

    int a;

    // 取得記憶體空間
    dynArr = malloc( arrLen1 * arrLen2 * sizeof(int) );

    if( dynArr == NULL )
    {
        fprintf(stderr, "Error: unable to allocate required memory\n");
        return 1;
    }

    // 使用動態取得的記憶體空間
    int i, j;
    for (i = 0; i < arrLen1; ++i)
    {
        for (j = 0; j < arrLen2; ++j)
        {
            int index = i * arrLen2 + j;
            dynArr[index] = index;
            printf("%d \t", dynArr[index]);
        }
        printf ("\n");
    }

    // 釋放記憶體空間
    free(dynArr);

    system("pause");
    system("cls");
    printf("Hello world!\n");
    return 0;
}
