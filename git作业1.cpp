#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
//������������������λ���ֵĺͣ���λ���ֵ�ƽ���ͣ�����������
//�� 100~10000 �ڵ����г��������������ǵ�ƽ������
int isprime(int x)/*���������жϵĺ���*/
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
int sumofweights(int x)/*�����λ��֮�͵ĺ���*/
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
int sqreofweights(int x)/*�����λ��ƽ���͵ĺ���*/
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
	printf("10-10000�ڵĳ�������Ϊ��\n");
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
	printf("10-10000�ڹ���%d����������\n", count);
	printf("���ǵ�ƽ����Ϊ%lf", average / count);
	return 0;
}
