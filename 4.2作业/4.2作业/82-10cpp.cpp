#include<iostream>
int main()
{
	int day, week,day_c;
	scanf_s("%d", &day);
	week = day / 7;
	day_c = day % 7;
	printf("%d��%d��", week, day_c);
	return 0;
}