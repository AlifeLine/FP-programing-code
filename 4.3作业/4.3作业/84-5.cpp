#include<iostream>

int leapyear(int a) 
{

	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) { //�����ж�����
		return 1; //�����귵��1
	}
	else {
		return 0; //�������귵��0
	}

}

int calculateDate(int year, int month, int day) 
{

	int sum = 0, i;
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //����a�����ͨ��ÿ�µ�����
	int b[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 }; //����b������������

	if (leapyear(year) == 1) { //�ж��Ƿ�Ϊ����
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

int main() 
{

	int year, month, day, result;
	printf("������������\n");
	scanf("%d%d%d", &year, &month, &day); 
	result = calculateDate(year, month, day);
	printf("��%d��\n", result);
	return 0;
}