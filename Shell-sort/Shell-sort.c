
/*希尔排序*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

/*API*/
void initialize(int *array, int size);
void sort(int *array, int size);
bool less(int *array, int a, int b);
void exch(int *array, int i, int j);
void show(int *array, int size);
bool isSorted(int *array, int size);
double timeTrial(int n);
void test();

int main(void)
{
	test();
	return 0;
}

//初始化数组，为数组赋从a.txt文件中获得的初值
void initialize(int *array, int size)
{
	int i;
	errno_t err;
	FILE *fp;
	err = fopen_s(&fp, "randomNum.txt", "r");
	if (err)
	{
		printf("randomNum.txt打开失败！\n");
		return;
	}
	else
	{//如正确打开，进行赋值操作
		for (i = 0; i < size; i++)
		{
			fscanf_s(fp, "%d", &array[i]);
		}
		//show(array, size);
	}
}
//希尔排序
void sort(int *array, int size)
{
	int i, j;
	int h = 1;
	while (h < (size / 3))
	{
		h = 3 * h + 1;//1,4,13,40,121,364,1093,...
	}
	while (h >= 1)
	{//将数组变为h有序
		for (i = h; i < size; i++)
		{
			for (j = i; j >= h && less(array, j, j - h); j -= h)
			{
				exch(array, j, j - h);
			}
		}
		h = h / 3;
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
void show(int *array, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
//判断给定数组array的元素是否有序,顺序则返回1，否则返回0
bool isSorted(int *array, int size)
{
	int i;
	for (i = 1; i < size; i++)
	{
		if (less(array, i, i - 1))
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
//验证排序性能
void test()
{
	int i, n;
	double time;
	for (i = 250; true; i += i)
	{
		time = timeTrial(i);
		printf("%7d %5.1fs\n", i, time);
	}
}
