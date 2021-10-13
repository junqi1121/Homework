#define _CRT_SECURE_NO_WARNINGS
/*牛顿方法计算正浮点数的平方根*/
#include<stdio.h>
#include<math.h>
int main()
{
	double x, y,z;
	printf("Pleaase enter a postive number :");
	scanf("%lf",&x);
	y = 1;
	do {
		z = x / y;
		y = (y + z) / 2;

	} while (fabs(y - z) > 0.00010);
	/*for (y = 1; z=x/y;fabs(y-z)>0.000001)
	{
		y = (y + z) / 2;
	}*/
	printf("The number's square root is %lf",y);
	return 0;
}