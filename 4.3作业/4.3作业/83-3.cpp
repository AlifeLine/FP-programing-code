#include<iostream>
#include<math.h>
int main()
{
	double a, b, c, delta;
	scanf("%lf%lf%lf", &a, &b, &c);
	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
	{
		printf("���̵�һ�����=%.2lf+%.2lfi", -b / (2 * a), sqrt(-delta) / (2 * a));
		printf("���̵���һ�����=%.2lf-%.2lfi", -b / (2 * a), sqrt(-delta) / (2 * a));
	}
	else if(delta==0)
	{
		printf("������������ͬ��ʵ��=%.2lf", (-b) / (2 * a));
	}
	else
	{
		printf("���̵�һ��ʵ��=%.2lf",-b+sqrt(delta) / (2 * a));
		printf("���̵���һ��ʵ��=%.2lf", -b - sqrt(delta) / (2 * a));
	}
	return 0;
}