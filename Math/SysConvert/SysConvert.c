#include <stdio.h>
/***********************************************************
 * 
 * Function:    vSysConvert 
 * Description: Change Decimal num to Binary(2) or other system (进制转换) 
 * Developer:   Jack Kilby
 * First Breed: 2019-01-13
 * Parametric:  int bit, the system number, such as binary is 2 ...
 *              int src, the number needed to be convert.
 * Return:      void
 * 
 * ********************************************************/
void vSysConvert(int bit, int src)
{
    if(src > 0)
    {
        vSysConvert(bit, src/bit);
        printf("%d",src%bit);
    }
}

int main(void)
{
    int a=4, b=8, c = 22;

    vSysConvert(a, c);
    getchar();
    return 0;
}
