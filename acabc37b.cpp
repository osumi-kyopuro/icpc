#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<cmath>
#define ll long long
using namespace std;

int main() {
	ll n, q;
	cin >> n >> q;
	vector<ll>l(q),r(q),t(q),a(n,0);
	for (ll i = 0; i < q; i++) {
		cin >> l[i] >> r[i] >> t[i];
	}
	for (ll k = 0; k < q; k++) {
		for (ll i = 0; i < n; i++) {
			if (i + 1 >= l[k] && i + 1 <= r[k]) {
				a[i] = t[k];
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
