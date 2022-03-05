#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINES_NUM_OF_ARRAY  3
#define ROWS_NUM_OF_ARRAY   3
#define ARRAY_INPUT             //means input the array by your self
#define TRANSPOSE_METHOD    1   //0 means using a temp array.

void vPrintArray(int array[][ROWS_NUM_OF_ARRAY], int line, int rows)
{
    int i,j;
    for(i=0;i<line;i++)
    {
        printf("[ ");
        for(j=0;j<rows;j++)
        {
            printf("%4d",array[i][j]);
        }
        printf(" ]\n");
    }
}

void vArrayTranspose(int array[][ROWS_NUM_OF_ARRAY], int line, int rows)
{
#if TRANSPOSE_METHOD == 0 
    int array_temp[LINES_NUM_OF_ARRAY][ROWS_NUM_OF_ARRAY] = {0};
    int i,j;
    for(i=0;i<LINES_NUM_OF_ARRAY;i++)
    for(j=0;j<ROWS_NUM_OF_ARRAY;j++)
    {
        array_temp[i][j] = array[j][i];
        array_temp[j][i] = array[i][j];
    }
    
    for(i=0;i<LINES_NUM_OF_ARRAY;i++)
    for(j=0;j<ROWS_NUM_OF_ARRAY;j++)
    {
        array[i][j] = array_temp[i][j];
        array[j][i] = array_temp[j][i];
    }
#endif
#if TRANSPOSE_METHOD == 1
    int i,j;
    int temp;
    for(i=0;i<LINES_NUM_OF_ARRAY;i++)
    for(j=0;j<i;j++)
    {
        if(j != i)
        {
            temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }
#endif
}


int main(void)
{
    int array[LINES_NUM_OF_ARRAY][ROWS_NUM_OF_ARRAY] = {0};
    int i;
#ifdef ARRAY_INPUT
    printf("Please your %d x %d Array with an Enter end of each line:\n",LINES_NUM_OF_ARRAY,ROWS_NUM_OF_ARRAY);
    fflush(stdout);

	for(i=0;i<LINES_NUM_OF_ARRAY;i++)
    {
        scanf("%d %d %d",&array[i][0],&array[i][1],&array[i][2]);
    }
#else
    srand((unsigned)time(NULL));
    for(i=0;i<LINES_NUM_OF_ARRAY;i++)
    {
        array[i][0] = rand()%100;
        array[i][1] = rand()%100;
        array[i][2] = rand()%100;
    }
#endif
    printf("Your input Array is :\n");
    vPrintArray(array,LINES_NUM_OF_ARRAY,ROWS_NUM_OF_ARRAY);
    vArrayTranspose(array,LINES_NUM_OF_ARRAY,ROWS_NUM_OF_ARRAY);
    printf("After transpose, the array is: \n");
    vPrintArray(array,LINES_NUM_OF_ARRAY,ROWS_NUM_OF_ARRAY);

    getchar();
    getchar();
    return 0;
}
