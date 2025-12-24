//컴퓨터학과 20230808 오승현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int data[100], count[10] = { 0 };//배열 count의 모든 값은 0 int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0,0};과 같은 의미
	int num;
	//srand(time(NULL));

	printf("Enter the number of random numbers:(<= 100): ");
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		data[i] = rand() % 10;

		for(int j=0;j<10;j++)
			if (data[i] % 10 == j)
				count[j]++;
	}
	for (int i = 0; i < 10; i++)
		printf("%d의 개수는 %d\n", i,count[i]);

	printf("-----------------------------------------------------\n");
	printf("발생된 난수는\n");
	for (int i = 0; i < num; i++)
	{
		printf("%5d\t", data[i]);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	
	return 0;
}