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
	ll n,m,sum=0;
	cin >> n >> m;
	vector<ll>x(m),sa(m-1,0);
	for (ll i = 0; i<m; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	for (ll i = 0; i<m-1; i++) {
		sa[i] = abs(x[i] - x[i + 1]);
	}
	sort(sa.begin(), sa.end());
	for (ll i = 0; i < m-n; i++) {
		sum += sa[i];
	}
	cout << sum << endl;

	



}