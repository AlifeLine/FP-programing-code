#include<iostream>
#include<string>
#include<set>
#include <sstream>
using namespace std;
int main()
{
    set<string> b; //����b����
    string a, tmp; //�����ַ���a��tmp,a���ڴ����û�������У�tmpΪ��ʱ����
    while (getline(cin, a))//һֱ��ȡ������
    {
        b.clear(); //�ͷ�b�������b������size
        if (a[0] == '#')//��#�н���
        {
            break;
        }       
        stringstream ss(a);//����stringstream���ss����a
        while (ss >> tmp)//��a��ĵ���һ��һ�������뵽tmp����
        {
            b.insert(tmp);//��tmp��ӵ�b�������棬����b�ڲ������ظ��Ķ������Լ���b��size����sizeΪ��ʵռ���ڴ��С
        }
        cout << b.size() << endl;//���b��size
    }
    return 0;
}