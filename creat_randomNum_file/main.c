
//生成一个txt文件，内容为N个以当前时间为种子的随机数
//用于排序算法的测试

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int i,N,MIN,MAX;
	int temp;
	FILE *fp;
	errno_t err = fopen_s(&fp, "randomNum.txt", "w+");	
	printf("生成随机数个数N:\n");
	scanf_s("%d", &N);
	if (err)
	{
		printf("创建文件randomNum.txt失败！\n");
		return;
	}
	else
	{
		srand((unsigned)time(NULL));
		for ( i = 0; i < N; i++)
		{
			fprintf_s(fp, "%d ", rand());
		}
		printf("生成成功！\n");
	}
}