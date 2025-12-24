//컴퓨터학과 20230808 오승현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int coins[4] = { 500,100,50,10 };
	int change;

	printf("Enter the amount of change:");
	scanf("%d", &change);

	for (int i = 0; i < 4; i++)
	{
		printf("%d coin: %d\n",coins[i], change / coins[i]);
		change = change%coins[i];
	}

	return 0;
}