#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>
#include<set>
#include<map>
#include<stack>
#define ll long long
using namespace std;

int main() {
	ll n,ans=0;
	cin >> n;
	vector<vector<ll>>a(3, vector<ll>(n+1,0));
	vector<vector<ll>>dp(3, vector<ll>(n + 1, 0));
	for (ll i = 1; i <= 2; i++) {
		for (ll j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	dp[1][1] = a[1][1];
	for (ll i = 1; i <=2; i++) {
		for (ll j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i - 1][j] + a[i][j], dp[i][j - 1] + a[i][j]);
		}
	}
	cout<< dp[2][n] << endl;
}
