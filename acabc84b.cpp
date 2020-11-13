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
	ll a, b;
	string s;
	cin >> a >> b >> s;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == '-'&&i != a) {
			cout << "No" << endl;
			exit(0);
		}
	}
	if (s.size() == a + b + 1 && s[a] == '-') {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
}