#include <stdio.h>

int main(void)
{
	int key, num, i, j, flag = 0;
	i = 0;
	j = 0;

	printf("Enter key: ");
	scanf_s("%d", &key);

	do
	{
		printf("Enter number(-1 for exit): ");
		scanf_s("%d", &num);

		if (key != num)
			i++;
		else
		{
			flag = 1;
			i++;

			if (j == 0)
				j = i;
		}
	} while (num != -1);

	if (flag == 0)
		printf("not found\n");
	else
		printf("%d\n", j);

	return 0;
}