#include<iostream>
using namespace std;
int main()
{
	struct worker
	{
		string name;
		int age;
		int fee;
	}work_info[3];
	work_info[0].name = "����";
	work_info[1].name = "����";
	work_info[2].name = "����";
	work_info[0].age = 25;
	work_info[1].age = 22;
	work_info[2].age = 30;
	work_info[0].fee = 2500;
	work_info[1].fee = 2300;
	work_info[2].fee = 3000;
	cout<<("����\t\t����\t\t��н\n");
	for (int i = 0; i < 3; i++)
	{
		cout << work_info[i].name << "\t\t" << work_info[i].age << "\t\t" << work_info[i].fee << endl;
	}
}