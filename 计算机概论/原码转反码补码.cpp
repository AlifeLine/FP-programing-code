#include <iostream>
#include <string>
using namespace std;
int main() {
	while (1) {
		cout << "����ԭ�룬�����ķ���λһ��Ҫд0" << endl;
		string s;
		cin >> s;
		if (s[0] == '0') {
			cout << "ԭ��,����,���붼��:" << s << endl;
		}
		else {
			cout << "ԭ��:" << s << endl;
			cout << "����:";
			cout << "1";        //����λ
			for (int i = 1; i < s.length(); i++) {
				if (s[i] == '.') cout << s[i];
				else if (s[i] == '1') cout << '0';
				else cout << '1';
			}
			cout << endl << "����:";
			for (int i = s.length(); i >= 0; i--) {
				if (s[i] == '1') {
					cout << "1";          //����λ
					for (int m = 1; m < i; m++) {
						if (s[m] == '.') cout << s[m];
						else if (s[m] == '1') cout << '0';
						else cout << '1';
					}
					for (int m = i; m < s.length(); m++) {
						cout << s[m];
					}
					break;
				}
				else {
					cout << "ERROR" << endl;
					break;
				}
			}
			cout << endl;
		}
	}
}