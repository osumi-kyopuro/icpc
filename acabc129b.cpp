#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
#include<climits>
#include<set>
#define ll long long
using namespace std;
int main() {
	ll n, r = 0;
	cin >> n;
	vector<ll>w(n), sum(n);
	for (ll i = 0; i < n; i++) {
		cin >> w[i];
		r += w[i];
		sum[i] = r;
	}
	ll ans = LLONG_MAX;
	for (ll i = 0; i < n; i++) {
		ll s1 = sum[i];
		ll s2 = sum[n - 1] - sum[i];
		ans = min(ans, abs(s1 - s2));

	}
	cout << ans << endl;

}


