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
	ll n, a, b;
	cin >> n >> a >> b;
	vector<string>s(n+1);
	vector<ll>sum(n + 1);
	for (ll i = 1; i <= n; i++) {
		s[i] = to_string(i);
		for (ll j = 0; j < s[i].size(); j++) {
			sum[i] += s[i][j] - '0';
		}
		//cout << i<<" "<<sum[i] << endl;
	}
	ll x = 0;
	for (ll i = 1; i <= n; i++) {
		if (sum[i] >= a && sum[i] <= b) {
			x += i;
		}
	}
	cout << x << endl;

}