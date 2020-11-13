#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<climits>
#include<set>
#include<map>
#define ll long long
using namespace std;
ll waru(ll x) {
	ll count = 0;
	while (x % 2 == 0) {
		x /= 2;
		count++;
	}
	return count;
}

int main() {
	ll n,sum=0;
	cin >> n;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += waru(a[i]);
	}
	cout << sum << endl;
}