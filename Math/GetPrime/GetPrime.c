#include <stdio.h>
#define SIZE 100
/***********************************************************
 * 
 * Function:    vGetPrime   
 * Description: Get the prime numbers from an number array（获取质数）
 * Developer:   Jack Kilby
 * First Breed: 2018-07-13
 * Parametric:  int prime[], the prime inputted
 *              int size, the size of the number array
 * Return:      void
 * 
 * ********************************************************/
void vGetPrime(int prime[], int size)
{
    int i = 2;
    int j = 0;
    
    while(i < (size/2+1))
    {
        for(j=i+1;j<size;j++)
        {
            while(prime[j] == 1)
                j++;

            if((j%i == 0) && (prime[j] == 0))
                prime[j] = 1;
        }
        i++;
    }
    for(j=1;j<size;j++)
    {
        if(prime[j] == 0)
        printf("%4d",j);
    }
}
int main(void)
{
    int iNum;
    int prime[SIZE] = {0};
    printf("Please input a num <= %d:\n",SIZE);
    scanf("%d",&iNum);
    vGetPrime(prime,iNum);
    
    getchar();
    getchar();
    return 0;
}