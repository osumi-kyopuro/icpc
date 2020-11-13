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
	if (s.size() == 1) {
		if (s[0] == 'a') {
			cout << -1 << endl;
		}
		else {
			cout << (char)(s[0] - 1) << endl;
		}
	}
	else {
		s.erase(s.end() - 1);
		cout << s << endl;
	}
}
