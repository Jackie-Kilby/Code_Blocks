#include <stdio.h>
/***************************

Function Name	: Salary Calculator
Developer		: Jack Kilby
First Breed		: 2018-06-06
Update			: 2018-06-06	First Breed
				  2018-06-07	Add A?B:C structure logic.
Description		: For calculate salary after tax from salary before tax.
				SALARY_MODE: 1,  by if-else structure logic:
								salary > 50000, Tax all with ratio 0.5;
								salary > 10000, Tax all with ratio 0.3;
								salary > 7000,  Tax all with ratio 0.2;
								salary > 5000,  Tax all with ratio 0.1;
								salary < 5000， do not tax.
							 2,  by A?B:C structure logic
Return			: void
Parametric		: none. Can use salary, mode or others when use.

****************************/
#define SALARY_MODE 2
void SalaryCalculator()
{
	float fSalaryBeforeTax = 0.0;			//税前工资
	float fSalaryAfterTax = 0.0;			//税后工资
	float fTaxRatio = 0.0;					//税率
	float fTax = 0.0;						//需缴纳税款 
		
	printf("Please Input your Salary before tax:");
	scanf("%f",&fSalaryBeforeTax);
#if SALARY_MODE == 1	
	if(fSalaryBeforeTax > 50000)
	{
		fTaxRatio = 0.5;
	}
	else if (fSalaryBeforeTax > 10000)
	{
		fTaxRatio = 0.3;
	}
	else if (fSalaryBeforeTax > 7000)
	{
		fTaxRatio = 0.2;
		printf("Your Salary is so low that is similar to Jack in 2018.\n");
	}
	else if (fSalaryBeforeTax > 5000)
	{
		fTaxRatio = 0.1;
	}
	else if (fSalaryBeforeTax >= 0)
	{
		fTaxRatio = 0;
	}
	else
	{
		printf("Your Salary is too low to be a minus num. \nWhat an amazing thing!\nHahahaha~~\n");
	}
	fTax = fTaxRatio * fSalaryBeforeTax;
	fSalaryAfterTax = (1-fTaxRatio) * fSalaryBeforeTax;
	//fSalaryAfterTax = fSalaryBeforeTax -fTax;			//As another calculation method with Tax calculated.
#endif
#if SALARY_MODE == 2
	fTaxRatio = fSalaryBeforeTax <= 5000 ? 0.0 : (
		fSalaryBeforeTax <= 7000 ? 0.1 : (
			fSalaryBeforeTax <= 10000 ? 0.2 : (
				fSalaryBeforeTax <= 50000 ? 0.2 : 0.5)));
	fTax = fTaxRatio * fSalaryBeforeTax;
	fSalaryAfterTax = (1-fTaxRatio) * fSalaryBeforeTax;
	//fSalaryAfterTax = fSalaryBeforeTax -fTax;			//As another calculation method with Tax calculated.
#endif

	printf("Your Salary after tax is %.2f,except Tax %.2f\n", fSalaryAfterTax, fTax);
}

int main()
{
	//Add a Module Salary Calculator here as a func.
	SalaryCalculator();
	return 0;
}
