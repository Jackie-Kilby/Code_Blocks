/***********************************************************
 * File Description: Show and accumulate algorithm for system covert(进制转换).
 * ********************************************************/
#include <stdio.h>


#define PRINTF_BIT_EN	1

#if PRINTF_BIT_EN
#define printf_bit	printf	
#else
#define printf_bit
#endif


/*************************** Common system convert method *******************************/
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
    if (dec > 0) {
        sys_convert_with_recursion(toType, dec/toType);
		printf_bit("[%d]", dec%toType);
		res_rec = res_rec*10 + dec%toType;
    }
	return res_rec;
}

/*************************** Decimal to Binary *******************************/
#define DECIMAL_TO_BINARY_METHOD_RECURSION	0
#define DECIMAL_TO_BINARY_METHOD_FOR_BITS	1
#define DECIMAL_TO_BINARY_METHOD			DECIMAL_TO_BINARY_METHOD_FOR_BITS
/***********************************************************
 * Function:    sys_convert_dec_to_bin 
 * Description: Change decimal to binary.
 * Developer:   Jack Kilby
 * First Breed: 2022-12-06
 * Parametric:  int num: input decimal value.
 * Return:      int : output value in Binary, using int value to show.
 * ********************************************************/
int sys_convert_dec_to_bin(int num)
{
	int bin = 0;

	//Judge num bits
	unsigned char bits = 31;
	for (bits=31; bits>0; bits--) {
		if ( num & (1<<bits) ) {
			break;
		}
	}

	for (int bitv = (1<<bits); bitv>0; bitv>>=1) {
	/*		
		if ( num & (1<<bits) ) {
			bin = bin*10 + 1;
		} else {
			bin = bin*10;
		}
	*/
		bin = bin*10 + !!(num & bitv);
		printf_bit("[%d]", !!(num & bitv));	
	}

	return bin;
}

/*************************** Middle API *******************************/
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
#if (DECIMAL_TO_BINARY_METHOD == DECIMAL_TO_BINARY_METHOD_RECURSION)
					res = sys_convert_with_recursion(2, num);
#elif (DECIMAL_TO_BINARY_METHOD == DECIMAL_TO_BINARY_METHOD_FOR_BITS)
					res = sys_convert_dec_to_bin(num);
#endif
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

/*************************** Program Entry *******************************/
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
		printf("\n%d covert from System-%d to System-%d is: %d.\n", num, from_type, to_type, result);
	} else {
		printf("\nSorry, System Convert from %d to %d is not supported now.", from_type, to_type);
	}
	
    getchar();
    return 0;
}

