#include <stdio.h>

int main(void)
{
	int deposit, target, i, j, save, year, month;
	i = 0;
	j = 0;

	printf("Enter deposit: ");
	scanf_s("%d", &deposit);
	printf("Enter target: ");
	scanf_s("%d", &target);
	save = deposit;

	while (i < target)
	{
		i += deposit;
		i *= 1.02;
		j++;
	}

	year = j / 12;
	month = j % 12;

	printf("%d %d %d\n", year, month, i);

	return 0;
}