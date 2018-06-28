#include <stdio.h>

/******************************************************
Function:   iGetFabonacciValue
Description:Get the value of Specific num of Fabonacci list
Developer:  Jack Kilby
Update:     2018/06/25
Parametric: void
Return:     int, the value of specific num of Fabonacci list
*******************************************************/
int iGetFabonacciValue()
{
    int iFaboNum = 0;
    int iFaboValue = 0;
    int i = 0;
    int iLastFaboNum = 1;
    int iNextFaboNum = 1;

    printf("Please input the order number of Fabonacci list:");
    scanf("%d",&iFaboNum);

    for (i=3 ; i<=iFaboNum ; i++)
    {
        iFaboValue = iLastFaboNum + iNextFaboNum;
        iLastFaboNum = iNextFaboNum;
        iNextFaboNum = iFaboValue;
    }
    printf("The No.%d Fabonacci value is %d.\n",iFaboNum,iFaboValue);

    return iFaboValue;
} 

int main(void)
{
    iGetFabonacciValue();
    char ch;
    ch = getchar();               //For Shell GUI
    return 0;
}

