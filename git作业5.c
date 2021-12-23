#define _CRT_SECURE_NO_WARNINGS
//作业5
//选作题
//输入一个字符串，形如
//3072x1728,2720x1536,2560x1600,2560x1440,2304x1728,2048x1536,1920x1200,1920x1080,1440x900,1280x800,1280x720,1024x768,1024x640,800x600,800x500,800x450,640x480,640x400,640x360,480x360,480x300,480x270,320x240,320x200,320x180,240x180,176x144,160x120,160x100,160x90
//这是一个显示器支持的分辨率清单，中间逗号分隔。
//现在输入画面的宽和高，然后在上述清单中挑选一个最接近的分辨率输出
//比如输入2000，1000，输出的分辨率应该是1920x1080，因为其它分辨率的误差更大。
//完成如下程序
// 2021-11-14
#include <stdio.h>
struct info 
{
    int lenth;
    int width;
};
int main()
{
    struct info menu[20];
    int x, y,i=0;
    char ress[20],a;
    while (1)
    {
        scanf("%s", ress);
        a = getchar();
        sscanf(ress, "%dx%d",&menu[i].lenth, &menu[i].width);
        i++;
        if (a == '\n')
        {
            break;
        }
    }
    scanf("%d %d", &x, &y);
    int min_err = fabs(x-menu[0].lenth)+fabs(y-menu[0].width);
    int number = 0;
    for (int j = 1; j < i; j++)
    {
        if (fabs(x - menu[i].lenth) + fabs(y - menu[i].width) < min_err)
        {
            min_err = fabs(x - menu[i].lenth) + fabs(y - menu[i].width);
            number = i;
        }
    }
    printf("选中的分辨率是%dx%d\n",menu[number].lenth,menu[number].width);
    return 0;
}

