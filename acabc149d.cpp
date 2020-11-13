#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>
#include<set>
#include<map>
#define ll long long
using namespace std;

int main() {
	ll n, k, r, s, p,sum=0;
	cin >> n >> k >> r >> s >> p;
	string t;
	cin >> t;
	string my=t;
	for (ll i = 0; i < my.size(); i++) {
		my[i] = 'o';
	}
	
	for (ll i = 0; i < t.size(); i++) {
		if (t[i] == 'r') {
			if (i<k) {
				sum += p;
				my[i] = 'p';
				//cout << sum << endl;
			}
			else if (i - k >= 0 && t[i - k] != 'r') {
				sum += p;
				my[i] = 'p';
				//cout << sum << endl;
				
			}
			else if (i - k >= 0 && t[i - k] == 'r'&&my[i-k]!='p') {
				my[i] = 'p';
				sum += p;
				
			}
			
		}
		else if (t[i] == 's') {
			if (i<k) {
				sum += r;
				my[i] = 'r';
				//cout << sum << endl;
			}
			else if (i - k >= 0 && t[i - k] != 's') {
				sum += r;
				my[i] = 'r';
				//cout << sum << endl;
			}
			else if (i - k >= 0 && t[i - k] == 's'&&my[i-k]!='r') {
				my[i] = 'r';
				sum += r;
			}
		}
		else {
			if (i<k) {
				sum += s;
				my[i] = 's';
				//cout << sum << endl;
			}
			else if (i - k >= 0 && t[i - k] != 'p') {
				sum += s;
				my[i] = 's';
				//cout << sum << endl;
			}
			else if (i - k >= 0 && t[i - k] == 'p'&&my[i-k]!='s') {
				my[i] = 's';
				sum += s;
			}
		}
	}
	cout << sum << endl;
}