#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int main() {
	ll N, W,sum=0;
	cin >> N>>W;
	vector<ll>w(N+1,0);
	vector<ll>v(N+1,0);
	vector<vector<ll>>dp(N+1,vector<ll>(W+1,0));
	for (ll i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < W + 1; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j + w[i + 1] <= W) {
				dp[i + 1][j + w[i + 1]] =
					max(dp[i + 1][j + w[i + 1]], dp[i][j] + v[i + 1]);
			}
		}
	}
	cout << dp[N][W] << endl;
}