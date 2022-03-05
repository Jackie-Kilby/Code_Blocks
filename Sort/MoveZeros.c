#include <stdio.h>
/* 牛客网：https://www.nowcoder.com/practice/102586387caa4afcbad6f96affce9780 */
/************************************************
 * 
 * Function Name:   moveZeros
 * Description:     Move all zeros to the end of an given array.
 * Developer:       Jack Kilby
 * Parametrics:     int* num: A given int array to be sorted.
 *                  int numsLen: The length of the given array.
 *                  int* returnSize: The length of the array, actually it point to a num equal to numsLen.
 * Return:          int*: The result array of given array.
 * First Breed:     2022-03-04
 * Update:          2018-03-05      Add if(numsLen == n) to exit immediately when all zeros are moved to the end. 
 * 
 * **********************************************/
int* moveZeros(int* nums, int numsLen, int* returnSize)
{
	int n=0, z=0;	//z point to zero, n point to first num after zero
	for (z=0; z<numsLen; z++) {
		if (0 == nums[z]) {
			for (n=z+1; n<numsLen; n++) {
				if (0 != nums[n]) {
					nums[z] = nums[n];
					nums[n] = 0;
					break;
				}
			}
			if (numsLen == n) {
				break;	//n point to last member, and has been set to zero
			}
		}
	}
	*returnSize = numsLen;
	return nums;
}

int main(void)
{
	int array[] = {1,2,5,0.0,3,12,4,0,6,8,0};
	int size = 0;
	
	//Show Input
	int i = 0;
	printf("Input[%d]:", sizeof(array)/sizeof(array[0]));
	for (i=0; i<sizeof(array)/sizeof(array[0]); i++) {
		printf("%d, ", array[i]);
	}
	printf("\r\n");

	moveZeros(array, sizeof(array)/sizeof(array[0]), &size);

	//Show Output
	printf("Output[%d]:", size);
	for (i=0; i<size; i++) {
		printf("%d, ", array[i]);
	}
	printf("\r\n");
}
