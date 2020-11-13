#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<cmath>
#include<map>
#define ll long long
using namespace std;

int main() {
	string s;
	int t;
	cin >> s >> t;
	ll x=0,y=0,count=0;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == 'L') {
			x--;
		}
		else if (s[i] == 'R') {
			x++;
		}
		else if (s[i] == 'U') {
			y++;
		}
		else if (s[i] == 'D') {
			y--;
		}
		else {
			count++;
		}
	}
	if (t == 1) {
		cout << count + abs(x) + abs(y) << endl;
	}
	else {
		if (abs(x)+abs(y)>=count) {
			cout << abs(x) + abs(y) - count << endl;
		}
		else {
			if (((count - (abs(x) + abs(y))) % 2) != 0) {
				cout << '1' << endl;
			}
			else {
				cout << '0' << endl;
			}
		}
	}
}