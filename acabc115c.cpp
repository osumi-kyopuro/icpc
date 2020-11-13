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
	ll n, k,c=0,sma=LLONG_MAX;
	cin >> n >> k;
	vector<ll>h(n),sa(n-1),sumsa(n-1,0);
	for (ll i = 0; i < n; i++) {
		cin >> h[i];
	}
	sort(h.begin(), h.end());
	for (ll i = 0; i < n-k+1; i++) {
		sma = min(sma, abs(h[i] - h[i + k - 1]));
	}
	
	cout << sma << endl;

	


}