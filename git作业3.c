#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define GESHU 10/*****在这里改所求结果的个数*****/

/***********************************************
f(n)函数的定义为0~n中包含的1的个数
f(13)是0~13中包含1的有 1，10，11，12，13，所以f(13)=6
f(1) = 1。
求另一个f(n)=n的n值
***********************************************/
int numbercheck(int x)//用于确定数字x中含有几个1
{	
	if (x <= 9&&x>=0)
	{
		if (x == 1)
		{
			return 1;
		}
		else {
			return 0;
		}
	}
	if (x >=10)
	{
		return (numbercheck(x % 10) + numbercheck(x / 10));
	}
}
int main() {
	int i = 2;
	int a = 1;
	int c = 0;
	while(1)
	{
		int count=0;
		a += numbercheck(i);
		count = a;
		if (count == i)
		{
			printf("%d\n", count);
			c++;
		}
		i++;
		if (c == GESHU)//确定所求结果的个数，在宏定义上改变
		{
			break;
		}
	}
	return 0;
}
//运行结果为以下这些数（部分）：
//0（显然）
//1（显然）
//199981
//199982
//199983
//199984
//199985
//199986
//199987
//199988
//199989
//199990
//200000
//200001
//1599981
//1599982
//1599983
//1599984
//1599985
//1599986
//1599987
//1599988
//1599989
//1599990
//2600000
//2600001
//13199998
//35000000
//35000001
//35199981
//35199982
//35199983
//35199984
//35199985
//35199986
//35199987
//35199988
//35199989
//35199990
//35200000
//35200001

