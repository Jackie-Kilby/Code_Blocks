#include <stdio.h>
#include <stdlib.h>
#define SHOW 1

int main(void)
{
	int guess = 1;
	srand((int)time(0));
	int secret = rand()%10;
#if SHOW
	printf("secret num is = %d.\n", secret);
#endif
	char ch;
	printf("Guess which num I am thinking, it is 0~9\n");
	printf("(press s, I will tell you)\n");
	
	//If get a 'y', stop immediately.
	while((ch = getchar())!='s')
	{
		if(secret == (ch - 0x30))
		{
			printf("Congratulations! You guessed the number right.\n");
			break;
		}
		else if(ch <= '9' && ch >= '0')
			printf("Guess again!\n");
		else
			printf("You press something I donot know.\n");
		while(getchar() != '\n');
	}
	if(ch == 's')
	{
		printf("Let me tell you, the secret number is %d!\n", secret);
	}
	printf("Press any key to end the game.");
	//get a 'y'
	
	getchar();
	getchar();
	return 0;
}


