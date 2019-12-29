#include <iostream>
#include<string.h>
#include<stdlib.h>
typedef struct  s
{
	char no[10], bookname[20], writer[25], cbs[25];
	int year, month, day;
	int price;
	int number;
	struct  s* next;

}book;

book* add(book* head, book** tail)//���ͼ��
{
	int i;
start:
	printf("ѡ���������:\n");
	printf("    1    ������ײ�\n");
	printf("    2    �����µ��鼮��Ϣ\n");
	printf("    3    �����β��\n");
	printf("    0    ����\n");
	scanf("%d", &i);
	switch (i)
	{
	case 0:break;
	case 1:
	{

		book* p;
		p = (book*)malloc(sizeof(book));
		printf("������ӵ�ͼ���ţ�");
		fflush(stdin);
		std::cin >> p->no;
		printf("����������");
		fflush(stdin);
		gets_s(p->bookname);
		printf("�������ߣ�");
		fflush(stdin);
		gets_s(p->writer);
		printf("�������������");
		fflush(stdin);
		gets_s(p->cbs);
		printf("�����������:");
		scanf("%d%d%d", &(p->year), &(p->month), &(p->day));
		printf("���뵥��:");
		scanf("%d", &(p->price));
		printf("������:");
		scanf("%d", &(p->number));
		p->next = head->next;
		head->next = p;
		if ((*tail)->next != NULL)
			(*tail) = (*tail)->next;
		printf("%s\n", (*tail)->no);
		printf("\n");
		printf("****************************\n");
		printf("    ��ӳɹ�!\n");
		printf("****************************\n");
		printf("\n");
	}break;

	case 2:
	{
		book* p, * q;
		char no[20];
		p = (book*)malloc(sizeof(book));
		printf("��Ҫ���뵽�ı���������ţ�");
		fflush(stdin);
		std::cin >> no;
		for (q = head->next; q && strcmp(q->no, no) != 0; q = q->next)
			;
		if (q == NULL)
			printf("δ�ҵ���ţ�����ʧ��!\n");
		else
		{
			printf("������ӵ�ͼ���ţ�");
			fflush(stdin);
			gets_s(p->no);
			printf("����������");
			fflush(stdin);
			gets_s(p->bookname);
			printf("�������ߣ�");
			fflush(stdin);
			gets_s(p->writer);
			printf("�������������");
			fflush(stdin);
			gets_s(p->cbs);
			printf("�����������:");
			scanf("%d%d%d", &(p->year), &(p->month), &(p->day));
			printf("���뵥��:");
			scanf("%d", &(p->price));
			printf("������:");
			scanf("%d", &(p->number));
			p->next = q->next;
			q->next = p;
		}
	}break;
	case 3:
	{
		book* p;
		p = (book*)malloc(sizeof(book));
		printf("������ӵ�ͼ���ţ�");
		fflush(stdin);
		gets_s(p->no);
		printf("����������");
		fflush(stdin);
		gets_s(p->bookname);
		printf("�������ߣ�");
		fflush(stdin);
		gets_s(p->writer);
		printf("�������������");
		fflush(stdin);
		gets_s(p->cbs);
		printf("�����������:");
		scanf("%d%d%D", &(p->year), &(p->month), &(p->day));
		printf("���뵥��:");
		scanf("%d", &(p->price));
		printf("������:");
		scanf("%d", &(p->number));
		(*tail)->next = p;
		(*tail) = p;
		(*tail)->next = NULL;
	}break;
	default:printf("����������밴��ʾ���в���!\n"); goto start;

	}

	return head;

}
void search_cbs(book* head)
{
	char no[10];
	book* p;
	int flag = 1;//�ж��Ƿ��ҵ���Ӧ�鼮 
	printf("�������������:");
	fflush(stdin);
	std::cin>>no;
	for (p = head->next; p; p = p->next)
	{
		if (strcmp(p->cbs, no) == 0)//��������ͬ���鲻Ψһ 
		{
			printf("ͼ����  ����      ����      ������\t�� �� �� ��      ����    �����\n");
			printf("%-10s%-10s%-10s%-10s%-5d%-4d%-8d%-8d%d\n", p->no, p->bookname, p->writer, p->cbs, p->year, p->month, p->day, p->price, p->number);
			flag = 0;//�ҵ��ˣ�����if��ִ�С� 
		}
	}
	if (flag)
	{
		printf("\n");
		printf("****************************\n");
		printf("    û�ҵ�����鼮!\n");
		printf("****************************\n");
		printf("\n");
	}
}
book* delete_(book* head, book** tail)
{
	char no[20];
	int i, n = 0;
	book* p, * q;
	bool flag=false;
	printf("������Ҫɾ�����鼮��ţ�");
	fflush(stdin);
	scanf("%s", no);
	fflush(stdin);
	for (q = head->next; q; q = q->next)
	{
		n++;
		if (strcmp(q->no, no) == 0)
		{
			flag = true;
			break;
		}
	}
	if (!flag)//�ձ����q�ƶ������һ����� 
		printf("δ�ҵ���ţ�ɾ��ʧ��!\n");
	else//�ҵ���Ҫɾ���Ľ�� 
	{
		for (i = 0, p = head->next; i < n; i++)//�ҵ�ǰһ�����
			p = p->next;
		p->next = q->next;//������Ҫɾ���Ľ��	
		printf("****************************\n");
		printf("    ɾ���ɹ�!\n");
		printf("****************************\n");
		printf("\n");

	}
	return head;
}
void search_all(book* head)//���ͼ����Ϣ
{
	book* p;
	printf("ͼ����  ����      ����      ������\t�� �� �� ��      ����    �����\n");
	for (p = head->next; p != NULL; p = p->next)
		printf("%-10s%-10s%-10s%-10s%-5d%-4d%-8d%-8d%d\n", p->no, p->bookname, p->writer, p->cbs, p->year, p->month, p->day, p->price, p->number);
}


int main()
{
	int x, lenth = 0, flag = 5;
	book* head, * tail;
	head = (book*)malloc(sizeof(book));
	head->next = NULL;
	tail = head;
	char no[20] = "123", mm[20];
	printf("��ӭ��������Ա!\n");
	while (flag)//���Ƶ�½ʧ�ܴ���
	{
		printf("���������Ա����:");
		fflush(stdin);
		gets_s(mm);
		if (strcmp(mm, no) == 0)//��½�ɹ��ſ��Խ������Աҳ��
		{
			while (1)
			{
				printf("---------------------------\n");
				printf("      ͼ����Ϣ����ϵͳ     \n");
				printf("---------------------------\n");
				printf("   1\t���ͼ��\n");
				printf("   2\t���������ѯͼ��\n");
				printf("   3\tɾ��ָ��������ͼ��\n");
				printf("   4\t�޸Ĵ���ͼ����Ϣ\n");
				printf("   5\t���ͼ����Ϣ\n");
				printf("   0\t�˳�\n");
				printf("---------------------------\n");
				printf("��ѡ��");
				scanf("%d", &x);
				switch (x)
				{
				case 1:head = add(head, &tail); break;
				case 2:search_cbs(head); break;
				case 3:head = delete_(head, &tail); break;
				case 5:search_all(head); break;
				case 0:return 0; break;
				default:printf("������������������\n");
				}
			}
		}
		else
		{
			flag--;
			if (flag)
				printf("������������ɳ���%d�Σ�ʧ�ܺ󴰿ڽ��رգ�", flag);
			else if (flag == 0)
				printf("��½ʧ�ܣ����ڽ��رա�\n");
		}


	}
}