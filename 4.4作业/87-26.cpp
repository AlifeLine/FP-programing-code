#include<iostream>
int main()
{
	int n1, n2,max,min;
	scanf("%d%d", &n1, &n2);
	if (n1 <= n2)
	{
		max = n2;
		min = n1;
	}
	else
	{
		max = n1;
		min = n2;
	}
	for (int i = max; i>0; i--)
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			printf("���Լ��Ϊ%d\n", i);
			break;
		}
	}
	for (int j = min; j <= 100000; j++)
	{
		if (j%n1==j%n2)
		{
			printf("��С������Ϊ%d", j);
			break;
		}
	}
}