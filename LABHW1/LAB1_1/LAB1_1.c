//컴퓨터학과 20230808 오승현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int num[5];
	int sum=0;

	for (int i = 0; i < 5; i++) 
	{
		printf("Enter %dth number :", i + 1);
		scanf("%d",&num[i]);
		sum = sum + num[i];
	}

	printf("---------------------------------------------\n");
	printf("총합은 %d\n",sum);
	printf("평균은 %d\n", sum/5);

	printf("---------------------------------------------\n");
	for (int i = 0; i < 5; i++) 
		printf("array[%d]:%d\n",i,num[i]);
	
}