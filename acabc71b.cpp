#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<climits>
#include<map>
#define ll long long
using namespace std;
int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (s[0] != 'a') {
		cout << 'a' << endl;
	}
	else {
		for (ll i = 0; i < s.size() - 1; i++) {
			if (s[i] + 1 < s[i + 1]) {
				cout << (char)(s[i] + 1) << endl;
				exit(0);
			}
		}
		set<ll>x;
		for (ll i = 0; i < s.size(); i++) {
			x.insert(s[i]);
		}
		if (x.size() == 26) {
			cout << "None" << endl;
		}
		else {
			cout << (char)(s[s.size()-1]+1) << endl;
		}

	}
}
