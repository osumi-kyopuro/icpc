#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int>a(m);
	vector<int>b(m);
	vector<int>c(m,0);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		vector<bool>cc(n, false);
		for (int j = 0; j < b[i];j++) {
			int p; cin >> p;
			cc[p-1] = true;
		}
		
		for (int j = n-1; j >= 0;j--) {
			c[i] *= 2;
			if (cc[j]) {
				c[i] += 1;
		    }
		}
	}
	int inf = 1000000000;
	vector<vector<int>>dp(m + 1, vector<int>((int)(pow(2, n)), inf));
	dp[0][0] = 0;
    for (int i = 0; i < m;i++) {
		for (int j = 0; j < pow(2, n);j++) {
			
			if (dp[i][j]!=inf) {

				dp[i + 1][j] = min(dp[i+1][j],dp[i][j]);

				dp[i + 1][j | c[i]] = min(dp[i][j]+a[i],dp[i+1][j|c[i]]);

			}
		}
	}
	/*
	for (int i = 0; i <= m;i++) {
		for (int j = 0; j < pow(2,n);j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	if (dp[m][(int)(pow(2,n))-1]!=inf) {
		cout << dp[m][(int)(pow(2, n) - 1)] << endl;
	}
	else {
		cout << -1 << endl;
	}
}