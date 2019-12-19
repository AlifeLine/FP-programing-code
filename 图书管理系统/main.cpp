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
bool check_book_name(string book_name)
{
	for (int j = 0; j < i; j++)
	{
		if (book_name == Book_info[j].book_name)
		{
			return true;
		}
	}
	return false;
}
void edit_line(int n,int book_id,string book_name,string book_author,string chuban,int year,int mounth,int day,float price,int num )
{
	char buf[4096];    //ÿ��ȡһ�У��������ݷŵ���������
	FILE* fp = fopen("library.txt", "r");     //filepath����ԭ���� 
	FILE* fpt = fopen("temp.txt", "w");    //��filepath�ļ���n������ɾ�������temp.txt�� 
	int i_lines = 0,i_out_line=0;
	while (i_lines<i)
	{
		i_lines++;
		if (i_lines == (n+1)) //ɾ����n�У���ʵ���Ƕ�����n��ʱ�������ƶ�һ���ļ�ָ�룬�����
		{          //����ȡ����һ���ļ����ݷŵ���ʱ�ļ���temp.txt�У��������ν��ɾ��
			fgets(buf, sizeof(buf), fp);   //����Ҫ��һ�У���Ϊ���Ϻ��ļ�ָ�뽫���ƶ�
			fprintf(fpt, "%d %s %s %s %d %d %d %f %d\n",book_id,book_name.c_str(),book_author.c_str(),chuban.c_str(),year, mounth,day,price,num);
		}
		else
		{
			fgets(buf, sizeof(buf), fp);
			fprintf(fpt, "%s", buf);
		}
	}
	fclose(fp);
	fclose(fpt);

	fpt = fopen("temp.txt", "r");
	fp = fopen("library.txt", "wb");   //���filepath�ļ�
	fclose(fp);

	fp = fopen("library.txt", "a");
	while (i_out_line < i)
	{
		i_out_line++;
		fgets(buf, sizeof(buf), fpt);
		fprintf(fp, "%s", buf);
	}

	fclose(fp);
	fclose(fpt);

	system("ERASE temp.txt");   //ɾ���ļ�temp.txt,ʹ�ø�������Ҫ����<stdlib.h>�ļ�
}
void del_line(int n)
{
	char buf[4096];    //ÿ��ȡһ�У��������ݷŵ���������
	FILE* fp = fopen("library.txt", "r");     //filepath����ԭ���� 
	FILE* fpt = fopen("temp.txt", "w");    //��filepath�ļ���n������ɾ�������temp.txt�� 
	int i_lines = 0, i_out_line = 0;
	while (i_lines < i)
	{
		i_lines++;
		if (i_lines == (n + 1)) //ɾ����n�У���ʵ���Ƕ�����n��ʱ�������ƶ�һ���ļ�ָ�룬�����
		{          //����ȡ����һ���ļ����ݷŵ���ʱ�ļ���temp.txt�У��������ν��ɾ��
			fgets(buf, sizeof(buf), fp);   //����Ҫ��һ�У���Ϊ���Ϻ��ļ�ָ�뽫���ƶ�
		}
		else
		{
			fgets(buf, sizeof(buf), fp);
			fprintf(fpt, "%s", buf);
		}
	}
	fclose(fp);
	fclose(fpt);

	fpt = fopen("temp.txt", "r");
	fp = fopen("library.txt", "wb");   //���filepath�ļ�
	fclose(fp);

	fp = fopen("library.txt", "a");
	while (i_out_line < i-1)
	{
		i_out_line++;
		fgets(buf, sizeof(buf), fpt);
		fprintf(fp, "%s", buf);
	}

	fclose(fp);
	fclose(fpt);

	system("ERASE temp.txt");   //ɾ���ļ�temp.txt,ʹ�ø�������Ҫ����<stdlib.h>�ļ�
}
void del_book()
{
	string del_book_name;
	char tag;
	FILE* p1, * p2;
	int k = 0;
	cout << "��������Ҫɾ�����������" << endl;
	cin >> del_book_name;
	if (check_book_name(del_book_name))
	{
		system("cls");
		cout << "��Ҫɾ��������:" << del_book_name << "\n" << "��ȷ���Ƿ��޸�(Y/N)\n";
		cin >> tag;
		if (tag == 'y' || tag == 'Y')
		{
			for (int j = 0; j < i; j++)
			{
				if (del_book_name == Book_info[j].book_name)
				{
					del_line(j);
					p1 = fopen("id.txt", "w");
					i = i - 1;
					fprintf(p1, "%d", i);
					fclose(p1);
					p2 = fopen("library.txt", "r");
					int k = 0;
					char book_name_tmp[50], book_author_tmp[50], book_chuban_tmp[50];
					while (!feof(p2))
					{
						fscanf(p2, "%d %s %s %s %d %d %d %f %d", &Book_info[k].book_id, book_name_tmp, book_author_tmp, book_chuban_tmp, &Book_info[k].chuban_date.year, &Book_info[k].chuban_date.month, &Book_info[k].chuban_date.day, &Book_info[k].price, &Book_info[k].num);
						Book_info[k].book_name = book_name_tmp;
						Book_info[k].book_author = book_author_tmp;
						Book_info[k].chuban = book_chuban_tmp;
						k++;
					}
					fclose(p2);
					cout << "ɾ���ɹ�\n\n" << endl;
					system("pause");
					break;
				}
			}
		}
	}
	else
	{
		cout << "û���Ȿ��Ŷ" << endl;
	}
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
	bool flag = 0;
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
			flag = 1;
		}
	}
	if (!flag)
	{
		cout << "û���ҵ��ó�����,��ѯʧ��,���ڷ�����һ���˵�";
		printf("\n\n\n");
		system("pause");
	}
	else
	{
		printf("\n\n\n");
		system("pause");
	}
}
void edit_book()
{
	string book_edit;
	string new_book_author,new_book_chuban;
	char tag;
	int new_date_year, new_date_mounth, new_date_day, new_num;
	float new_book_price;
	int options;
	cout << "������Ҫ�༭ͼ�������\n";
	fflush(stdin);
	cin >> book_edit;
	system("cls");
	for (int j = 0; j < i; j++)
	{
		if (book_edit == Book_info[j].book_name)
		{
			system("cls");
			cout << "�ҵ��˸�ͼ��,һ���Ǹ�ͼ�����Ϣ"<<endl;
			printf("|------------------------------------ͼ����Ϣ------------------------------------|\n");
			printf("|���  ����        ����      ������            ��������     ����       �����    |\n");
			printf("|                                                                                |\n");
			printf("|%-6d%-12s%-10s%-16s  %-d %-2d %-3d  %-8.1f    %-9d|\n", Book_info[j].book_id, Book_info[j].book_name.c_str(), Book_info[j].book_author.c_str(), Book_info[j].chuban.c_str(), Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
			printf("\n\n\n");
			printf("\t\t\t *=======================================*\n");
			printf("\t\t\t| * - * - * -���������ѡ�� * - * - * - * |\n");
			printf("\t\t\t| *                                     * |\n");
			printf("\t\t\t| |  [1]   �޸�����                     | |\n");
			printf("\t\t\t| *                                     * |\n");
			printf("\t\t\t| |  [2]   �޸ĳ�����                   | |\n");
			printf("\t\t\t| *                                     * |\n");
			printf("\t\t\t| |  [3]   �޸ĳ�������                 | |\n");
			printf("\t\t\t| *                                     * |\n");
			printf("\t\t\t| |  [4]   �޸ĵ���                     | |\n");
			printf("\t\t\t| *                                     * |\n");
			printf("\t\t\t| |  [5]   �޸Ŀ����                   | |\n");
			printf("\t\t\t| *                                     * |\n");
			printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
			printf("\t\t\t *=======================================*\n");
			cin >> options;
			switch (options)
			{
			case 1:
				
				cout << "�������µ�������Ϣ\n";
				cin >> new_book_author;
				system("cls");
				cout << "��������µ�������ϢΪ:" << new_book_author<<"\n"<<"��ȷ���Ƿ��޸�(Y/N)\n";
				cin >> tag;
				if (tag=='y'||tag=='Y')
				{
					Book_info[j].book_author = new_book_author;
					cout << "�޸ĳɹ�\n�µ���ϢΪ:\n";
					printf("|%-6d%-12s%-10s%-16s  %-d %-2d %-3d  %-8.1f    %-9d|\n", Book_info[j].book_id, Book_info[j].book_name.c_str(), Book_info[j].book_author.c_str(), Book_info[j].chuban.c_str(), Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
					edit_line(j, Book_info[j].book_id, Book_info[j].book_name, Book_info[j].book_author, Book_info[j].chuban, Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
				}
				break;
			case 2:

				cout << "�������µĳ�������Ϣ\n";
				cin >> new_book_chuban;
				system("cls");
				cout << "��������µĳ�������ϢΪ:" << new_book_chuban << "\n" << "��ȷ���Ƿ��޸�(Y/N)\n";
				cin >> tag;
				if (tag == 'y' || tag == 'Y')
				{
					Book_info[j].chuban = new_book_chuban;
					cout << "�޸ĳɹ�\n�µ���ϢΪ:\n";
					printf("|%-6d%-12s%-10s%-16s  %-d %-2d %-3d  %-8.1f    %-9d|\n", Book_info[j].book_id, Book_info[j].book_name.c_str(), Book_info[j].book_author.c_str(), Book_info[j].chuban.c_str(), Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
					edit_line(j, Book_info[j].book_id, Book_info[j].book_name, Book_info[j].book_author, Book_info[j].chuban, Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
				}
				break;
			case 3:

				cout << "�������µĳ�������Ϣ\n";
				cin >> new_date_year;
				cout << "�������µĳ�������Ϣ\n";
				cin >> new_date_mounth;
				cout << "�������µĳ�������Ϣ\n";
				cin >> new_date_day;
				system("cls");
				cout << "��������µĳ���������ϢΪ:" << new_date_year+ new_date_mounth +new_date_day << "\n" << "��ȷ���Ƿ��޸�(Y/N)\n";
				cin >> tag;
				if (tag == 'y' || tag == 'Y')
				{
					Book_info[j].chuban_date.year = new_date_year;
					Book_info[j].chuban_date.month = new_date_mounth;
					Book_info[j].chuban_date.day = new_date_day;
					cout << "�޸ĳɹ�\n�µ���ϢΪ:\n";
					printf("|%-6d%-12s%-10s%-16s  %-d %-2d %-3d  %-8.1f    %-9d|\n", Book_info[j].book_id, Book_info[j].book_name.c_str(), Book_info[j].book_author.c_str(), Book_info[j].chuban.c_str(), Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
					edit_line(j, Book_info[j].book_id, Book_info[j].book_name, Book_info[j].book_author, Book_info[j].chuban, Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
				}
				break;
			case 4:

				cout << "�������µĵ���\n";
				cin >> new_book_price;
				system("cls");
				cout << "��������µĵ���Ϊ:" << new_book_price << "\n" << "��ȷ���Ƿ��޸�(Y/N)\n";
				cin >> tag;
				if (tag == 'y' || tag == 'Y')
				{
					Book_info[j].price = new_book_price;
					cout << "�޸ĳɹ�\n�µ���ϢΪ:\n";
					printf("|%-6d%-12s%-10s%-16s  %-d %-2d %-3d  %-8.1f    %-9d|\n", Book_info[j].book_id, Book_info[j].book_name.c_str(), Book_info[j].book_author.c_str(), Book_info[j].chuban.c_str(), Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
					edit_line(j, Book_info[j].book_id, Book_info[j].book_name, Book_info[j].book_author, Book_info[j].chuban, Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
				}
				break;
			case 5:

				cout << "�������µĿ���� \n";
				cin >> new_num;
				system("cls");
				cout << "��������µĿ���� Ϊ:" << new_num << "\n" << "��ȷ���Ƿ��޸�(Y/N)\n";
				cin >> tag;
				if (tag == 'y' || tag == 'Y')
				{
					Book_info[j].num = new_num;
					cout << "�޸ĳɹ�\n�µ���ϢΪ:\n";
					printf("|%-6d%-12s%-10s%-16s  %-d %-2d %-3d  %-8.1f    %-9d|\n", Book_info[j].book_id, Book_info[j].book_name.c_str(), Book_info[j].book_author.c_str(), Book_info[j].chuban.c_str(), Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
					edit_line(j, Book_info[j].book_id, Book_info[j].book_name, Book_info[j].book_author, Book_info[j].chuban, Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
				}
				break;
			default:
				cout << "û�����ѡ��Ŷ";
				break;
			}
		}
	}
	printf("\n\n\n");
	system("pause");
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
void view_all_book()
{
	system("cls");
	printf("|------------------------------------ͼ����Ϣ------------------------------------|\n");
	printf("|���  ����        ����      ������            ��������     ����       �����    |\n");
	printf("|                                                                                |\n");
	for (int j = 0; j < i; j++)
	{
		printf("|%-6d%-12s%-10s%-16s  %-d %-2d %-3d  %-8.1f    %-9d|\n", Book_info[j].book_id, Book_info[j].book_name.c_str(), Book_info[j].book_author.c_str(), Book_info[j].chuban.c_str(), Book_info[j].chuban_date.year, Book_info[j].chuban_date.month, Book_info[j].chuban_date.day, Book_info[j].price, Book_info[j].num);
	}
	system("pause");
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
			case 3: del_book(); break;
			case 4: edit_book(); break;
			case 5: view_all_book(); break;
			case 6: login_menu(); break;
			default:cout << "�����������������"; break;
			}
		}
	}
}