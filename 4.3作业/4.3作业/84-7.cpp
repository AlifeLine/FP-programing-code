#include<iostream>
int main()
{
	int option;
	float n1, n2;
	printf("������������������\n");
	scanf("%f%f", &n1, &n2);
	printf("��ϣ������������ʲô����\n1.�ӷ�\n2.����\n3.�˷�\n4.����\n");
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		printf("%.0f", (n1 + n2));
		break;
	case 2:
		printf("%.0f", (n1 - n2));
		break;
	case 3:
		printf("%.0f", (n1 * n2));
		break;
	case 4:
		printf("%.2f", (n1 / n2));
		break;
	default:
		printf("��������ȷ������\n");
		break;
	}
}