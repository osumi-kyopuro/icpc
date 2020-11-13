#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#define ll long long
using namespace std;
int main() {
	ll N, W, sum = 0,x=0;
	cin >> N >> W;
	vector<ll>w(N + 1, 0);
	vector<ll>v(N + 1, 0);
	vector<vector<ll>>dp(N + 1, vector<ll>(100001, LLONG_MAX));
	dp[0][0] = 0;
	for (ll i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
		dp[i][0] = 0;
	}
	
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < 100001; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			if (j + v[i + 1] <= 100000&&dp[i][j]!=LLONG_MAX) {
				dp[i + 1][j + v[i + 1]] =
					min(dp[i + 1][j + v[i + 1]], dp[i][j] + w[i + 1]);
				
			}
			
		}
	}
	
	for (ll i = 100000; i >=0; i--) {
		if (dp[N][i] <= W) {
			cout << i << endl;
			break;
		}
	}
}