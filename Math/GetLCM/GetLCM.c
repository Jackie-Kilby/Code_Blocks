#include <stdio.h>
/******************************************************************
 * 
 * Function Name:   iGetLeasetCommonMultiple
 * Description:     Get the least common multiple(LCM) of two numbers, for example, the LCM of 30 and 40 is 120
 * Developer:       Jack Kilby
 * Update:          2018-06-29
 * Parametric:      void
 * Return:          int, iLCM, the LCM of 2 special numbers. 
 * 
 * ****************************************************************/
int iGetLeastCommonMultiple(void)
{
    int iNum1 = 0 , iNum2 = 0;
    int iLCM = 0;
    printf("Please give me 2 numbers with a space in the middle:\n");
    scanf("%d %d", &iNum1, &iNum2);

    //Get LCM here
    iLCM = (iNum1 > iNum2) ? iNum1 : iNum2;
    for(; iLCM < iNum1*iNum2; iLCM++)
    {
        if((iLCM % iNum1 == 0) && (iLCM % iNum2 == 0))
        break;
    }

    printf("The LCM is %d !\n",iLCM);
    return iLCM;
}


int main(void)
{
    printf("This program will give you Least Common Multiple of 2 numbers!\n");
    iGetLeastCommonMultiple();
    printf("End with Enter pressed.");
    char a = getchar();
    char b = getchar();
    return 0;
}