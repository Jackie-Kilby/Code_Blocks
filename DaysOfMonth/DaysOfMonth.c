#include <stdio.h>

#define FALSE 	0
#define TRUE	1
typedef int		bool_t;

/***************************************************

Function Name:  bJudgeLeapYear
Developer: 		Jack Kilby
First Breed: 	2018-06-06
Update:			2018-06-07
Description:	Judge whether a special year is a leap year.
Return:			TRUE  or 1		//means the year is a leap year
				False or 0		//means the year is not a leap year
Parametric:		int Year, the year num, used to decide if the year is a leap year.

***************************************************/
bool_t bJudgeLeapYear(int Year)
{
	if(0 != (Year%4))
	{
		return FALSE;
	}
	else if(0 == (Year%100))
	{
		if(0 == (Year%400))
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return TRUE;
	}
}

/***************************************************

Function Name:  iGetDaysofMonth
Developer: 		Jack Kilby
First Breed: 	2018-06-06
Update:			2018-06-07
Description:	Get the num of days in a special month in a special year.
Return:			int iDaysOfMonth, The days of a special month in a special year.
Parametric:			int iMonth, spec in 1~12
				int iYear, the year num, used to decide if the February is in leap year.

***************************************************/
int iGetDaysOfMonth(int MonthNum,int YearNum)
{
	int iDaysOfMonth;
	
	switch(MonthNum)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		iDaysOfMonth = 31;
		break;
		
	case 4:
	case 6:
	case 9:
	case 11:
		iDaysOfMonth = 30;
		break;
		
	case 2:
		if(bJudgeLeapYear(YearNum))
		{
			iDaysOfMonth = 29;
		}
		else
		{
			iDaysOfMonth = 28;
		}
		
		break;
		
	default:
		iDaysOfMonth = 0;
		break;
	}
	
	if(iDaysOfMonth == 0)
	{
		printf("You have input an wrong month number.\n");
	}
	
	return iDaysOfMonth;
}


int main()
{
	int iMonth = 0;
	int iYear = 0;
	int iDaysOfMonthYear = 0;
	
	printf("Please Input the Month Num:");
	scanf("%d",&iMonth);
	printf("Please Input the Year Num:");
	scanf("%d",&iYear);
	
	iDaysOfMonthYear = iGetDaysOfMonth(iMonth, iYear);
	if(0 != iDaysOfMonthYear)
	{
		printf("Month %d has %d days.",iMonth,iDaysOfMonthYear);	//Jack: use enum datatype "string" instead of %d(iMonth)
	}
	return 0;
}
