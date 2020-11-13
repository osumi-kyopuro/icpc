#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<ll>dp(n+1, LLONG_MAX);
	vector<ll>a = { 1,6,9,36,81,216,729,1296,6561,7776,46656,59049 };
	dp[0] = 0;
	for (ll i =0; i <= n; i++) {
		for (ll j = 0; j < a.size(); j++) {
			if (i+a[j]<=n) {
				dp[i + a[j]] = min(dp[i]+1, dp[i+a[j]]);

			}
		}
	}
	for (ll i = 0; i <= n; i++) {
		//cout << dp[i] << endl;
	}
	cout << dp[n] << endl;
}