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
	ll si = 0;
	vector<string>t(s.size());
	ll st = 0;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] != s[i + 1]) {
			t[st] = s.substr(si,i - si + 1);
			st++;
			si = i + 1;
		}
	}
	for (ll i = 0; i < t.size(); i++) {
		if (t[i].size() > 0) {
			cout << (char)(*t[i].begin())  << t[i].size();
		}
	}
	cout << endl;

}
