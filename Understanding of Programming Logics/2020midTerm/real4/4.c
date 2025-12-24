#include <stdio.h>

int main(void)
{
	int m, n, i, j, total;
	total = 0;

	printf("Enter m: ");
	scanf_s("%d", &m);
	printf("Enter n:");
	scanf_s("%d", &n);

	for (j = m; j <= n; j++)
	{ 
		//int flag = 1;
		for (i = 2; i < j; i++)
		{
			if (j % i == 0)
			{
				//flag = 0;
				break;
			}
		}
			if (j % i != 0) //flag == 1
			{
				total = total + j;
			}
		
	}
	printf("%d\n", total);
	
		return 0;
}
//으악 모르겠다

