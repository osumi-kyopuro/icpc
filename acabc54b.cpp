#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#define ll long long
using namespace std;

int main() {
	ll m, n,sentoui=-1,sentouj=-1,idoui,idouj;
	cin >> n >> m;
	vector<string>a(n);
	vector<string>b(m);
	vector<vector<ll>>count(n, vector<ll>(n, 0));
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (ll i = 0; i <= n-m; i++) {
		for (ll j = 0; j <= n-m; j++) {
			if (a[i][j] == b[0][0]) {
				sentoui = i;
				sentouj = j;
				//cout << sentoui << endl;
				//cout << sentouj << endl;
				//count++;
				for (ll i = sentoui; i-sentoui<m;  i++) {
					for (ll j = sentouj; j-sentouj< m; j++) {
						if (a[i][j] == b[i-sentoui][j-sentouj]) {
							count[sentoui][sentouj]++;
						}
					}
				}
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if (count[i][j] == m * m) {
				cout << "Yes" << endl;
				exit(0);
			}
		}
	}
	cout << "No" << endl;
	




}