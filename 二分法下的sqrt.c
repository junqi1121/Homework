#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
/*My sqrt*/
int main()
{
	float left, right,mid;
	float x;
	printf("Please enter a number to sqrt:");
	scanf("%f",&x);
	right = x + 1;/*加一是为了使小于1的数也可以二分*/
	left = 0;
	mid = (left + right) / 2;
	while (fabs(mid * mid - x) >= 0.0000001)/*fabs是求绝对值，需要引math.h头。还可以通过right-left来控制精确度*/
	{
		if (mid * mid > x)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
		mid = (left + right) / 2;
		
	}
	printf("The sqrt of the number is %f",mid);
	return 0;
}