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
	ll n,z=0;
	cin >> n;
	vector<ll>a(n),sum(n,0);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		z += a[i];
		sum[i] = z;
	}
	ll sma = LLONG_MAX;
	for (ll i = 0; i < n;i++) {
		sma = min(sma, abs(sum[n - 1] - 2*sum[i]));
	}
	cout << sma << endl;

}