#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int a[101][101]={0}, b[101][101], c[101][101],d[101][101];
int main()
{
	int x, h;
	//输入图像矩阵的长和卷积核的长 
	scanf("%d%d", &x, &h);
	//输入图像矩阵a
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= x; j++)
			scanf("%d", &a[i][j]);
	//输入卷积核b
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= h; j++)
			scanf("%d", &b[i][j]);
	//卷积核旋转180,后存到c中
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= h; j++)
		{
			c[i][j] = b[h - i+1][h - j+1];
		}
	}
	//计算卷积结果
	int middle = h / 2 + 1;
	for(int i=1;i<=x;i++)
		for (int j = 1; j <= x; j++)
		{
			int sum = 0;
			for(int k=1;k<=h;k++)
				for (int l = 1; l <= h; l++)
				{
					if (i - (middle - k) >= 1 && i - (middle - k) <= x
						&& j - (middle - l) >= 1 && j - (middle - l) <= x)//判断坐标是否在图像内矩阵内 
						sum += c[k][l] * a[i - (middle - k)][j - (middle - l)];
				}
			d[i][j] = sum;
		}
	//打印最终结果
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
return 0;
}
