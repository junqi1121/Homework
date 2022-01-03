#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
//超级素数：它本身，各位数字的和，各位数字的平方和，都是素数。
//求 100~10000 内的所有超级素数，及它们的平均数。
int isprime(int x)/*用于素数判断的函数*/
{
	int y = 2;
	for (y = 2; y <= sqrt(x); y++)
	{
		if (x% y == 0)
		{
			return 0;
		}
	}
	return 1;
}
int sumofweights(int x)/*求各个位数之和的函数*/
{
	if (x < 10)
	{
		return x;
	}
	if (x >= 10)
	{
		return (x % 10 + sumofweights(x / 10));
	}
}
int sqreofweights(int x)/*求各个位数平方和的函数*/
{
	if (x < 10)
	{
		return x * x;
	}
	if (x >= 10)
	{
		return(sqreofweights(x % 10) + sqreofweights(x / 10));
	}
}
int main()
{
	int a = 10;
	double average = 0;
	int count = 0;
	printf("10-10000内的超级素数为：\n");
	for (a = 10; a < 10000; a++)
	{
		if (isprime(a))
		{
			int sum;
			sum=sumofweights(a);
			int sqre;
			sqre = sqreofweights(a);
			if (isprime(sum) && isprime(sqre))
			{
				printf("%d\n", a);
				average += a;
				count++;
			}
		}
	}
	printf("10-10000内共有%d个超级素数\n", count);
	printf("他们的平均数为%lf", average / count);
	return 0;
}
