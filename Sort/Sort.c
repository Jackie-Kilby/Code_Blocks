#include <stdio.h>
#define LENGTH_OF_SORT_ARRAY    10

#define SORT_METHOD 2       //0 means 冒泡排序,1 means 直接插入排序, 2 means 选择排序

void vPrintArray(int array[], int len);

/************************************************
 * 
 * Function Name:   vSortArray
 * Description:     Sort for a given int array
 *                  SORT_METHOD 0,  冒泡排序
 *                              1， 直接插入排序
 *                              2， 选择排序
 * Developer:       Jack Kilby
 * Parametrics:     int array, array[], A given int array to be sorted.
 *                  int len, the length of the given array
 * Return:          void
 * First Breed:     2018-07-04
 * Update:          2018-07-15      Change the printf location. 
 * 
 * **********************************************/
void vSortArray(int array[], int len)
{
#if SORT_METHOD == 0
    int i = 0;
    int j = 0;
    int temp = 0;

    for(i=0 ; i<len ; i++)
    {
        for(j=0 ; j<len-i-1 ; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
#endif 

#if SORT_METHOD == 1
    int i = 0;
    int j = 0;
    int temp = 0;

    for(i=1;i<len;i++)
    {
        for(j=i;j>0;j--)
        {
            if(array[j] < array[j-1])
            {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }

#endif 

#if SORT_METHOD == 2
    int i = 0;
    int j = 0;
    int iMinIndex = 0;
    int temp;

    for(i=0;i<len;i++)
    {
        iMinIndex = i;
        for(j=i+1;j<len;j++)
        {
            if(array[iMinIndex] > array[j])
            {
                iMinIndex = j;
            }
        }
        if(iMinIndex != i)
        {
            temp = array[i];
            array[i] = array[iMinIndex];
            array[iMinIndex] = temp;
        }
    }

#endif 
}

void vPrintArray(int array[], int len)
{
    int i = 0;
    for(i=0 ; i<len ; i++)
    {
        printf("%4d",array[i]);
    }
    printf(" ]\n");

}

int main(void)
{
    //A given array definition.
    int iArray[LENGTH_OF_SORT_ARRAY];
    int i = 0;
    printf("Please input the array to be sorted:\n");
    while(i < LENGTH_OF_SORT_ARRAY)
    {
        printf("the %d number is:\n",i);
        scanf("%d",&iArray[i]);
        ++i;
    }
    //Print out the Array before sort.
    printf("Your input Array is [");
    vPrintArray(iArray, LENGTH_OF_SORT_ARRAY);

    vSortArray(iArray, LENGTH_OF_SORT_ARRAY);

    //Print out the Array after sort.
    printf("Your sorted Array is [");
    vPrintArray(iArray, LENGTH_OF_SORT_ARRAY);
    getchar();
    getchar();
    return 0;
}
