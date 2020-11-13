#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<map>
#define ll long long
using namespace std;

int main() {
	ll n, x,sum=0;
	cin >> n >> x;
	vector<ll>a(n);
	vector<int>b(n,0);
	for (ll i = 0; i < n; i++) {
		b[i] = x % 2;
		x = x / 2;
	}
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < n; i++) {
		if (b[i] > 0) {
			sum += a[i];
		}
	}
	cout << sum << endl;



}
