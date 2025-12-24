#include <stdio.h>

int main(void)
{
	int n, i, total;
	total = 0;

	printf("Enter Á¤¼ö: ");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
			total += i;
	}

	printf("%d\n", total);

	return 0;
}