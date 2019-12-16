#include <iostream>
#include <map>
#include <string>
using namespace std;

string tolowwer(string s) {
	string res = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') 
		{
			s[i] = s[i] + 32;
		}
		res += s[i];
	}
	return res;
}

bool split_or_not(char ch) 
{
	if (ch == ',' || ch == '.' || ch == ' ') {
		return true;
	}
	return false;
}

void text_check(string s) 
{
	string temp = "";
	map<string, int> text_map;//����text_map��һ��map����
	for (int i = 0; i < s.length(); i++) 
	{
		if (!split_or_not(s[i])) 
		{
			temp += s[i];
		}
		else {
			if (temp == "") 
			{
				continue;
			}
			//����һ���ָ���������temp�Ƿ��Ѿ���map�У�����map����valueֵ��1���������һ��keyֵ
			//�˴���ʾû���ҵ�keyΪtemp��map
			//map.find���û���ҵ��ͷ���map.end()��ֵ
			if (text_map.find(temp) == text_map.end()) 
			{
				text_map[temp] = 1;
			}
			//����ҵ���value  +1
			else 
			{
				int value = text_map[temp];
				value++;
				text_map[temp] = value;
			}
			temp = "";//��temp��ʼ��Ϊ��������һ�����ʵĴ���
		}
	}
	map<string, int>::iterator print_map;//�����������������
	for (print_map = text_map.begin(); print_map != text_map.end(); print_map++) 
	{
		cout << print_map->first << ":" << print_map->second << endl;
	}

}

int main(int n) {
	string s1;
	getline(cin, s1);
	string s = tolowwer(s1);
	text_check(s);
	return 0;
}