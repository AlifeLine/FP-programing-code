#include<iostream>
int main()
{
	int n[20];
	int z = 0, f = 0, zero = 0;
	for (int i = 0; i < 20; i++)
	{
		scanf("%d", &n[i]);
		if (n[i] < 0)
		{
			f++;
		}
		else if (n[i] == 0)
		{
			zero++;
		}
		else
		{
			z++;
		}
	}
	printf("������%d��\n", z);
	printf("������%d��\n", f);
	printf("0��%d��\n", zero);
}