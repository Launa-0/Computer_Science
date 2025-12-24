#include <stdio.h>

int main(void)
{
	int month, i;

	printf("Enter month: ");
	scanf_s("%d", &month);

	if (month >= 1 && month <= 12)
	{
		if (month == 1)
			i = 1;
		else if (month == 2)
			i = 2;
		else if (month == 3)
			i = 3;
		else if (month == 4)
			i = 4;
		else if (month == 5)
			i = 5;
		else if (month == 6)
			i = 6;
		else if (month == 7)
			i = 7;
		else if (month == 8)
			i = 8;
		else if (month == 9)
			i = 9;
		else if (month == 10)
			i = 10;
		else if (month == 11)
			i = 11;
		else if (month == 12)
			i = 12;
		printf("%d¿ù\n", i);
	}

	else
		printf("incorrect\n");

	return 0;
}