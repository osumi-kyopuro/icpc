#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
#define ll long long
using namespace std;
bool teamcheck(ll k,vector<ll>a,vector<ll>f,ll c) {
	ll syugyou=0;
	for (ll i = 0; i < a.size(); i++) {
		syugyou +=max( a[i] - c/f[i] , (ll)(0));
	}
	if (syugyou > k) {
		return false;
	}
	return true;
}

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll>a(n);
	vector<ll>f(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < n; i++) {
		cin >> f[i];
	}
	sort(a.begin(), a.end(), greater<ll>());
	sort(f.begin(), f.end());
	
	ll left=0,right=pow(10,12)+1;
	while (left <= right) {
		if (teamcheck(k,a,f,(left+right)/2)) {
			right = (left + right) / 2-1;
		}
		else {
			left= (left + right) / 2+1;
		}
	}
	cout<<left<<endl;
}