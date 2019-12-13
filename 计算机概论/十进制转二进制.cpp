#include <stdio.h>
#include <math.h>

long long _10to2(int n);

int main()
{
	int n;
	printf("����һ��ʮ������: ");
	scanf("%d", &n);
	printf("ʮ������ %d ת��Ϊ������λ %lld", n, _10to2(n));
	return 0;
}

long long _10to2(int n)
{
	long long _2Number = 0;
	int remainder, i = 1, step = 1;

	while (n != 0)
	{
		remainder = n % 2;
		printf("Step %d: %d/2, ���� = %d, �� = %d\n", step++, n, remainder, n / 2);
		n /= 2;
		_2Number += remainder * i;
		i *= 10;
	}
	return _2Number;
}