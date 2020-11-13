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
	ll m, n;
	cin >> n >> m;
	vector<ll>a(n),b(n),c(m),d(m);
	for (ll i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (ll i = 0; i < m; i++) {
		cin >> c[i] >> d[i];
	}
	vector<ll>x(n,LLONG_MAX);
	ll saisyouj = 0,mae;
	for (ll i = 0; i < n; i++) {
		for (ll j =0; j <m; j++) {
			mae = x[i];
			x[i] = min((abs(a[i] - c[j]) + abs(b[i] - d[j])), x[i]);
			if (mae != x[i]) {
				saisyouj = j;
			}
		}
		cout << saisyouj + 1 << endl;

	}
}

