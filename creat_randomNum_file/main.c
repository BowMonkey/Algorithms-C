
//����һ��txt�ļ�������ΪN���Ե�ǰʱ��Ϊ���ӵ������
//���������㷨�Ĳ���

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int i,N,MIN,MAX;
	int temp;
	FILE *fp;
	errno_t err = fopen_s(&fp, "randomNum.txt", "w+");	
	printf("�������������N:\n");
	scanf_s("%d", &N);
	if (err)
	{
		printf("�����ļ�randomNum.txtʧ�ܣ�\n");
		return;
	}
	else
	{
		srand((unsigned)time(NULL));
		for ( i = 0; i < N; i++)
		{
			fprintf_s(fp, "%d ", rand());
		}
		printf("���ɳɹ���\n");
	}
}