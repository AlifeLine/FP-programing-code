#include<iostream>
int main()
{
	for (int i = 0;i <= 40; i++)
	{
		for (int  j = 0; j <= 100; j++)
		{
			for (int  k = 0; k <= 300; k=k+3)
			{
				if ((3 * i + j + k / 3) == 100)
				{
					printf("����%dֻ,ĸ��%dֻ,С��%dֻ\n", i, j, k);
				}
			}
		}
	}
}