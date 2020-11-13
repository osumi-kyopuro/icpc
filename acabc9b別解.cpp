#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#define ll long long
using namespace std;

int main() {
	ll n, m = 0, kotae = 0;
	cin >> n;
	set<ll>k;
	for (ll i = 0; i < n; i++) {
		ll t;
		cin >> t;
		k.insert(t);
	}
	cout << *(--(--k.end())) << endl;

}
