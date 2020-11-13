#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;
int main() {
	int n, W; cin >> n >> W;
	vector<ll> w(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	vector<vector<ll>> dp(n+1, vector<ll>(W + 1, 1e18));

}