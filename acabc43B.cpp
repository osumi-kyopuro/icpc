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
	vector<char>x(s.size());
	for (ll i = 0; i < s.size();i++) {
		if (s[i] == '0') {
			x[i]='0';
		}
		else if (s[i] == '1') {
			x[i] = '1';
		}
		else {
			if (i > 0) {
				for (ll j = i-1; j >=0; j--) {
					if (x[j] != ' ') {
						x[j] = ' ';
						x[i] = ' ';
						break;
					}
				}
			}

			x[i] = ' ';
		}
	}
	for (ll i = 00; i < s.size(); i++) {
		if (x[i] != ' ') {
			cout << x[i];
		}
	}
	cout << endl;
}



