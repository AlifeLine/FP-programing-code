#include<iostream>
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a + b < c || a + c < b || b + c < a)
	{
		printf("���ܹ���������");
	}
	else
	{
		if ((a * a + b * b == c * c&&a==b)||( a * a + c * c == b * b&&a==c)|| (c * c + b * b == a * a&&b==c))
		{
			printf("Ϊ����ֱ��������");
		}
		else if(a * a + b * b == c * c||a * a + c * c == b * b||c * c + b * b == a * a)
		{
			printf("Ϊֱ��������");
		}
		else
		{
			printf("Ϊ����������");
		}
	}
}