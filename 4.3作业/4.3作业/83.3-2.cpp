#include<iostream>
#include<math.h>
int main()
{
	float x, y, z;
	printf("�밴��(x,y)��������\n");
	scanf("(%f,%f)", &x, &y);
	if (x > 0 && y>0)
	{
		z = log(x) + log(y);
	}
	else if (x < 0 && y>0)
	{
		z = sin(x) + sin(y);
	}
	else if(x<0&&y<0)
	{
		z = exp(2 * x) + exp(3 * x);
	}
	else if(x>0&&y<0)
	{
		z = tan(x + y);
	}
	printf("%.2f", z);
}