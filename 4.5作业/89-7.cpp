#include<stdio.h>
#define M 10       // ����
int main(void)
{
	int a[M][M], i, j;   // ��ά�����ѭ��������a[��][��]
	for (i = 0; i < M; i++) // ÿһ��
	{
		for (j = 0; j <= i; j++) // ��ֵ��ӡ
		{
			if ((i == j || j == 0))
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			}
			printf("%-4d", a[i][j]);
		}
		printf("\n");
	}
}