
/*��������*/
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


int main(void)
{//��֤��������
	int i, n;
	double time;
	/*printf("׼����֤����������Ŀ��\n");
	scanf_s("%d", &n);*/
	for (i = 250; true; i += i)
	{
		time = timeTrial(i);
		printf("%7d %5.1fs\n", i, time);
	}
	return 0;
}

//��ʼ�����飬Ϊ���鸳��a.txt�ļ��л�õĳ�ֵ
void initialize(int *array, int size)
{
	int i;
	errno_t err;
	FILE *fp;
	err = fopen_s(&fp, "randomNum.txt", "r");
	if (err)
	{
		printf("a.txt��ʧ�ܣ�\n");
		return;
	}
	else
	{//����ȷ�򿪣����и�ֵ����
		for (i = 0; i < size; i++)
		{
			fscanf_s(fp, "%d", &array[i]);
		}
		//show(array, size);
	}
}
//��������
void sort(int *array, int size)
{
	int i,j;
	for ( i = 1; i < size; i++)
	{
		for ( j = i; j > 0; j--)
		{
			if (less(array,j,j-1))
			{
				exch(array, j, j - 1);
			}
		}
	}

}
//�Ƚ�����a��b�ڸ��������ж�Ӧֵ�Ĵ�С
//a<=b����true��a>b����false
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
//������������array����Ϊa��b��ֵ
void exch(int *array, int i, int j)
{
	int temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
//�ڿ���̨��ӡ��������array��ֵ
void show(int *array, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
//�жϸ�������array��Ԫ���Ƿ�����,˳���򷵻�1�����򷵻�0
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
//����n���������򲢼�ʱ
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
