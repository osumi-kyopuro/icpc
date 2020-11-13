#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>
#include<set>
#include<map>
#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	map<ll,ll>mp;
	for (ll i = 0; i < n; i++) {
		ll s;
		cin >> s;
		mp[s - 1] = i + 1;

	}
	for (ll i = 0; i < n; i++) {
		cout << mp[i] <<" ";
	}
	cout << endl;

}