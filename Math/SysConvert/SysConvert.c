/***********************************************************
 * File Description: Show and accumulate algorithm for system covert(进制转换).
 * ********************************************************/
#include <stdio.h>

/***********************************************************
 * Function:    sys_convert_with_recursion 
 * Description: Change decimal to any system with recursion method.
 * Developer:   Jack Kilby
 * First Breed: 2019-01-13
 * Update:		2022-12-04. review and modify.
 * Parametric:  int toType: convert decimal to what system, such as binary is 2.
 *              int dec: input decimal value.
 * Return:      int : output value in toType system, using int value to show.
 * ********************************************************/
int res_rec = 0;
int sys_convert_with_recursion(int toType, int dec)
{
    if(dec > 0)
    {
        sys_convert_with_recursion(toType, dec/toType);
		res_rec = res_rec*10 + dec%toType;
    }
	return res_rec;
}

/***********************************************************
 * Function:    sys_convert 
 * Description: middle API, used to call different implementation accoring to fromType, toType.
 * Developer:   Jack Kilby
 * First Breed: 2022-12-04
 * Parametric:  int fromType: the type (in value) system convert from, use 10 usually.
 *              int toType: the type (in value) system conver to.
 *              int num: the value to be converted.
 * Return:      int : the result after being converted.
 * ********************************************************/
int sys_convert(int fromType, int toType, int num)
{
	int res = 0;

	switch (fromType) {
		case 10: {
			switch (toType) {
				case 2:
					res = sys_convert_with_recursion(2, num);
					break;

				default:
					res = sys_convert_with_recursion(toType, num);
					break;
			}
			break;

		default:
			res =0;
			break;
		}
	}

	return res;
}

/***********************************************************
 * Function:    main 
 * Description: Ask user to input system convert related value.
 * Developer:   Jack Kilby
 * First Breed: 2022-12.04.
 * Parametric:  void
 * Return:      int 0: not used.
 * ********************************************************/
#define PRINT_NOW	fflush(stdout)			//Home PC need use this to printf out.
int main(void)
{
    int num=1, from_type=10, to_type = 2;			//Default is last tested SysConvert type.
	int result;

	printf("Please input your number: ");	PRINT_NOW;
	scanf("%d", &num);
	printf("What system is it? ");	PRINT_NOW;
	scanf("%d", &from_type);
	printf("What system do you want it to be converted? "); PRINT_NOW;
	scanf("%d", &to_type);


	result = sys_convert(from_type, to_type, num);
	if (result) {
		printf("%d covert from System-%d to System-%d is: %d.\n", num, from_type, to_type, result);
	} else {
		printf("Sorry, System Convert from %d to %d is not supported now.", from_type, to_type);
	}
	
    getchar();
    return 0;
}

