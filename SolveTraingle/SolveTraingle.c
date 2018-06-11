#include <stdio.h>
#define SOLVE_MODE	1
/**********************************************
Function Name	: vSolveTraingle
Developer		: Jack Kilby
First Breed		: 2018-06-08
Update			: 2018-06-08
Description		: Solve Traingle by some known conditions
					SOLVE_MODE == 1, means solve the traingle with 3 known sides.
Return			: void
Parametric		: none
**********************************************/
void vSolveTraingle()
{
#if SOLVE_MODE == 1
	float a,b,c;
	printf("Tell me the 3 sides of your traingle <a,b,c>:");
	scanf("%f,%f,%f",&a,&b,&c);
	
	//First Step, Make sure the 3 sides can construct a traingle.
	if ((a + b <= c) || (a + c <= b) || (b + c <= a))
	{
		printf("Sorry, your 3 sides can not construct a traingle");
		return;
	}

	//Second tep, Get the sides order by length order a < b < c with Bubbling Method.
	float temp;
	if(a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	else
	{
		if(b > c)
		{
			temp = b;
			b = c;
			c = temp;
		}
	}
	
	//Third Step, Make sure what kind of traingle this is.
	if( a*a + b*b == c*c)
	{
		if(a == b)
		{
			printf("This is a 等腰直角三角形.");
		}
		else
		{
			printf("This is a 直角三角形.");
		}
	}
	else
	{
		if(a == b)
		{
			if (a == c)
			{
				printf("This is a 等边三角形.");
			}
			else
			{
				printf("This is a 等腰三角形.");
			}
		}
		else
		{
			printf("This is a 锐角/钝角 三角形");
		}
	}
#endif
}

int main()
{
	vSolveTraingle();
	return 0;
}
