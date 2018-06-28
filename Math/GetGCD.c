#include <stdio.h>
/***********************************************************
 * 
 * Function:    iGetGreatestCommonDivisors
 * Description: Get the greatest common divisor of 2 numbers.
 * Developer:   Jack Kilby
 * Parametric:  void
 * Return:      int, greatest common divisor of 2 number.
 * 
 * ********************************************************/
int iGetGreatestCommonDivisors(void)
{
    int iGCD = 0;
    int iNumA = 0;
    int iNumB = 0;
    printf("Please input 2 numbers. I will give the GCD. 2 Num divided by a space: \n");
    scanf("%d %d",&iNumA,&iNumB);
    iGCD = iNumA > iNumB ? iNumA : iNumB;
    for ( ; iGCD > 0 ; iGCD--)
    {
        if((iNumA%iGCD == 0) && (iNumB%iGCD == 0))
        {
            break;
        }
    }
    printf("The GCD of the two numbers is %d\n",iGCD);

    return iGCD;
}

int main(void)
{
    printf("Get Greatest Commin Divisors from the numbers below.\n");
    iGetGreatestCommonDivisors();
    int a = getchar();
    int b = getchar();                                      //Jack: For not close the console window, need to input a ENTER here to close.
    return 0;
}