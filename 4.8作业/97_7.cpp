#include<iostream>
int cday(int year, int month, int day);
int main()
{
	printf("%d", cday(2019, 12, 21));
}
int cday(int year, int month, int day)
{
	int sum = 0, i;
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //����a�����ͨ��ÿ�µ�����
	int b[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 }; //����b������������

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) { //�ж��Ƿ�Ϊ����
		for (i = 0; i < month - 1; i++) {
			sum += b[i];
		}
	}
	else {
		for (i = 0; i < month - 1; i++) {
			sum += a[i];
		}
	}

	sum = sum + day;
	return sum;
}