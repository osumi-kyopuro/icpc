#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#define ll long long
using namespace std;

int main() {
	string s;
	cin >> s;
	bool flag = true;
	while (flag == true) {
		flag = false; 
		if (s.find('a') != -1) {
			s.erase(s.begin() + s.find('a'));
			flag = true;
		}
		if (s.find('i') != -1) {
			s.erase(s.begin() + s.find('i'));
			flag = true;
		}
		if (s.find('u') != -1) {
			s.erase(s.begin() + s.find('u'));
			flag = true;
		}
		if (s.find('e') != -1) {
			s.erase(s.begin() + s.find('e'));
			flag = true;
		}
		if (s.find('o') != -1) {
			s.erase(s.begin() + s.find('o'));
			flag = true;
		}

	}
	cout << s << endl;
}
