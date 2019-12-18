#include<iostream>
#include<cstring>
#include <fstream>
using namespace std;
#define ADMIN_PASS "1"
#define ADMIN_USER "1"
int i; //ͼ�������
typedef struct date
{
	int year;
	int month;
	int day;
};
typedef struct book_info
{
	int book_id;
	string book_name;
	string book_author;
	string chuban;//������
	date chuban_date;//��������
	float price;
	int num;//ʣ����
};
book_info Book_info[10001];
bool check_book()
{
	for (int j = 0; j < i; j++)
	{
		if (Book_info[i].book_name == Book_info[j].book_name)
		{
			return false;
		}
	}
	return true;
}
void add_book()
{
	string tmp_name;
	FILE* p1;
	FILE* p2;
	system("cls");
	printf("\t\t *==================================================================================*\n");
	printf("\t\t| * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * |\n");
	printf("\t\t| |          ����������   ���������ߣ������磬�����꣬�£��գ����ۣ������        | |\n");
	printf("\t\t| * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * |\n");
	printf("\t\t *==================================================================================*\n");
	fflush(stdin);
	while (true)
	{
		cout << "����:";
		cin >> Book_info[i].book_name;
		if (check_book())
		{
			cout << "����:";
			cin >> Book_info[i].book_author;
			cout << "������:";
			cin >> Book_info[i].chuban;
			cout << "������:";
			cin >> Book_info[i].chuban_date.year;
			cout << "������:";
			cin >> Book_info[i].chuban_date.month;
			cout << "������:";
			cin >> Book_info[i].chuban_date.day;
			cout << "����:";
			cin >> Book_info[i].price;
			cout << "�����:";
			cin >> Book_info[i].num;
			Book_info[i].book_id = i;
			//printf("%s", Book_info[i].book_author.c_str());
			p1 = fopen("library.txt", "a");
			p2 = fopen("id.txt", "w");
			fprintf(p1, "%d %s %s %s %d %d %d %f %d\n", Book_info[i].book_id, Book_info[i].book_name.c_str(), Book_info[i].book_author.c_str(), Book_info[i].chuban.c_str(), Book_info[i].chuban_date.year, Book_info[i].chuban_date.month, Book_info[i].chuban_date.day, Book_info[i].price, Book_info[i].num);
			fclose(p1);
			i++;
			fprintf(p2, "%d", i);
			fclose(p2);
			cout << "���ͼ��ɹ�\n";
			cout << "�Ա��ֵ������ļ�\n";
			break;
		}
		else
		{
			cout << "������������Ѵ�������������\n";
		}
	}

}
void search_book()
{
	string book_search;
	cout << "������Ҫ��ѯ�ĳ����������\n";
	fflush(stdin);
	cin >> book_search;
	system("cls");
	printf("|------------------------------------ͼ����Ϣ------------------------------------|\n");
	printf("|���  ����        ����      ������            ��������     ����       �����    |\n");
	printf("|                                                                                |\n");
	for (int j = 0; j < i; j++)
	{
		if (book_search == Book_info[j].chuban)
		{
			printf("|%-6d%-12s%-10s%-16s  %-d %-2d %-3d  %-8.1f    %-9d|\n",Book_info[j].book_id,Book_info[j].book_name.c_str(), Book_info[j].book_author.c_str(), Book_info[j].chuban.c_str(), Book_info[j].chuban_date.year, Book_info[j].chuban_date.month,Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
		}
	}
	printf("\n\n\n");
	system("pause");
	
}
void edit_book()
{

}
bool login_menu()
{
	int option;
	bool log;
	string pass, user;
	while (true)
	{
		system("cls");
		printf("\t\t\t *=======================================*\n");
		printf("\t\t\t| * - * - * ��ӭʹ��ͼ�����ϵͳ* - * - * |\n");
		printf("\t\t\t| |  [1]   ��¼                         | |\n");
		printf("\t\t\t| *                                     * |\n");
		printf("\t\t\t| |  [2]   �˳�                         | |\n");
		printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
		printf("\t\t\t *=======================================*\n");
		cin >> option;
		if (option == 2)
		{
			exit(0);
		}
		else if (option == 1)
		{
			system("cls");
			printf("\t\t\t *=======================================*\n");
			printf("\t\t\t| * - * - * - * - * - * * - * - * - * - * |\n");
			printf("\t\t\t| |        �������˺ź�����             | |\n");
			printf("\t\t\t| * - * - * - * - * - * * - * - * - * - * |\n");
			printf("\t\t\t *=======================================*\n");
			cout << "�˺�:";
			cin >> user;
			cout << "����:";
			cin >> pass;
			if (user == ADMIN_USER && pass == ADMIN_PASS)
			{
				cout << "��¼�ɹ����ڽ���ϵͳ" << endl;
				return true;
			}
			cout << "��¼ʧ��,���ص�¼��ҳ" << endl;
			system("pause");
		}
		else
		{
			cout << "�����������������";
		}
	}

}
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
	printf("\t\t\t| |  [5]   �˳���¼                     | |\n");
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
	FILE* p1;
	FILE* p2;
	system("title ͼ�����ϵͳ");
	if ((p2 = fopen("id.txt", "r")) == NULL)/*p2��ͼ�����ϵͳid�ļ�ָ��*/
	{
		p2 = fopen("id.txt", "w");
		fprintf(p2, "0");
		fclose(p2);
	}
	else
	{
		p2 = fopen("id.txt", "r");
		fscanf(p2, "%d", &i);
	}
	if ((p1 = fopen("library.txt", "r")) == NULL)/*p1��ͼ�����ϵͳ�����ļ�ָ��*/
	{
		p1 = fopen("library.txt", "w");
		fclose(p1);
	}
	else
	{
		p1 = fopen("library.txt", "r");
		int k = 0;
		char book_name_tmp[50], book_author_tmp[50],book_chuban_tmp[50];
		while (!feof(p1))
		{
			fscanf(p1, "%d %s %s %s %d %d %d %f %d",&Book_info[k].book_id, book_name_tmp, book_author_tmp, book_chuban_tmp, &Book_info[k].chuban_date.year, &Book_info[k].chuban_date.month, &Book_info[k].chuban_date.day, &Book_info[k].price, &Book_info[k].num);
			Book_info[k].book_name=book_name_tmp;
			Book_info[k].book_author=book_author_tmp;
			Book_info[k].chuban = book_chuban_tmp;
			k++;
		}
		fclose(p1);
	}
	if (login_menu())
	{
		while (true)
		{
			option = manager_menu();
			switch (option)
			{
			case 1: add_book(); break;
			case 2: search_book(); break;
			case 3:
			case 4:
			case 5: login_menu(); break;
			default:cout << "�����������������"; break;
			}
		}
	}
}