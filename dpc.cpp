#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
int main() {
	int n;
	cin >> n;
	//vector<int>a(n),b(n),c(n);
	vector<vector<ll>>dp(n,vector<ll>(3,0));
	for (int i =0 ; i < n; i++) {
		cin >> dp[i][0]>>dp[i][1]>>dp[i][2];
		if (i != 0) {
			dp[i][0] += max(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] += max(dp[i - 1][2], dp[i - 1][0]);
			dp[i][2] += max(dp[i - 1][1], dp[i - 1][0]);

			
		}
			
	}
	cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << endl;

}