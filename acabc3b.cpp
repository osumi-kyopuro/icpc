#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<map>
#define ll long long
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	if (s == t) {
		cout<< "You can win" << endl;
		exit(0);
	}
	bool flag = false;
	char a[7] = { 'a','t','c','o','d','e','r' };
	for (ll i = 0; i < s.size(); i++) {
		for (ll j = 0; j < 7; j++) {
			if (s[i] == '@' && t[i] == a[j]) {
				flag = true;
				break;
			}
			else if (t[i] == '@' && s[i] == a[j]) {
				flag = true;
				break;
			}
			else if (s[i] == '@'&&t[i] == '@') {
				flag = true;
				break;
			}
			else if ((s[i]=='@'||t[i]=='@')&&j == 6) {
				cout << "You will lose" << endl;
				exit(0);
			}
			else if (s[i] != '@'&&t[i]!='@'&&s[i]!=t[i]) {
				cout << "You will lose" << endl;
				exit(0);
			}
		}	
	}
	if (flag == true) {
		cout << "You can win" << endl;
	}
	else {
		cout << "You will lose" << endl;
	}
	
}
