#include<iostream>
using namespace std;
#define ADMIN_PASS "1"
#define ADMIN_USER "1"
int i; //ͼ�������
int list_len;//������ȫ�ֱ���
int manager_menu()
{
	int option;
	system("cls");
	printf("\n\n");
	printf("\t\t\t *=======================================*\n");
	printf("\t\t\t| * - * - * ��ӭʹ��ͼ�����ϵͳ* - * - * |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [1]   ���ͼ��                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [2]   ���������ѯͼ��             | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [3]   ɾ��ָ��������ͼ��           | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [4]   �޸Ĵ����ͼ����Ϣ           | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [5]   �鿴����ͼ��                 | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [6]   �˳���¼                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
	printf("\t\t\t *=======================================*\n");
	printf("\n\n\n");
	fflush(stdin);
	cin >> option;
	return option;
}
int main()
{
	int option;
	list_node* phead;
	phead = Create();
	system("title ͼ�����ϵͳ");
	if (login_menu())
	{
		while (true)
		{
			option = manager_menu();
			switch (option)
			{
			case 1: add_book(phead); break;
			case 2: search_book(phead); break;
			case 3: del_book(phead); break;
			case 4: edit_book(phead); break;
			case 5: view_all_book(phead); break;
			case 6: login_menu(); break;
			default:cout << "�����������������"; break;
			}
		}
	}
}