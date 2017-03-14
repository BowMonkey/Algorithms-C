
/*选择排序*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void initialize(int *array,int size);
void sort(int *array,int size);
bool less(int *array, int a, int b);
void exch(int *array, int i, int j);
void show(int *array,int size);
bool isSorted(int *array,int size);
double timeTrial(int n);


int main(void)
{//验证排序性能
	int i, n;
	double time;
	/*printf("准备验证的数据组数目：\n");
	scanf_s("%d", &n);*/
	for ( i = 250; true; i += i)
	{
		time = timeTrial(i);
		printf("%7d %5.1fs\n", i, time);
	}
	return 0;
}

//初始化数组，为数组赋从a.txt文件中获得的初值
void initialize(int *array,int size)
{
	int i ;
	
	//正确的手动输入方法
	/*printf("输入每个数组元素的值：\n");
	for ( i = 0; i < size; i++)
	{
		printf("array[%d]", i);
		scanf_s("%d", &array[i]);
	}*/
	
	//正确的从文件输入方法
	errno_t err;
	FILE *fp;
	err = fopen_s(&fp, "randomNum.txt", "r");
	if (err)
	{
		printf("a.txt打开失败！\n");
		return;
	}
	else
	{//如正确打开，进行赋值操作
		for ( i = 0; i < size; i++)
		{
			fscanf_s(fp, "%d", &array[i]);
		}
		//show(array, size);
	}
}
//选择排序
void sort(int *array,int size)
{
	int i, j, min;
	for ( i = 0; i < size; i++)
	{
		min = i;
		for ( j = i+1; j < size; j++)
		{
			if (less(array,j,min))
			{
				min = j;
			}
		}
		exch(array, i, min);
	}
}
//比较索引a和b在给定数组中对应值的大小
//a<=b返回true，a>b返回false
bool less(int *array, int a, int b)
{
	if (array[a] > array[b])
	{
		return false;
	}
	else 
	{
		return true;
	}

}
//交换给定数组array索引为a和b的值
void exch(int *array, int i, int j)
{
	int temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
//在控制台打印给定数组array的值
void show(int *array,int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
//判断给定数组array的元素是否有序,顺序则返回1，否则返回0
bool isSorted(int *array,int size)
{
	int i;
	for (i = 1; i < size; i++)
	{
		if (less(array, i,i-1))
			return false;
		return true;
	}
}
//处理n个数的排序并计时
double timeTrial(int n)
{
	int *array;
	clock_t start, end;
	array = malloc(sizeof(int) * n);
	initialize(array, n);
	start = clock();
	sort(array, n);
	end = clock();
	return difftime(end, start) / 1000;
}

//main备份
/*
int size;
int *array;
clock_t start, end;
printf("输入数组大小：\n");
scanf_s("%d", &size);
array = malloc(sizeof(int) * size);
initialize(array,size);
start = clock();
sort(array,size);
end = clock();
if (isSorted(array,size))
{
printf("排序已完成！\n");
printf("所用时间：%2.1f秒\n", difftime(end,start)/1000);
}
else
{
printf("排序失败！\n");
printf("所用时间：%d秒", difftime(end, start) / 1000);
}
//show(array,size);
return 0;
*/