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
	ll n;
	cin >> n;
	pair<pair<string, ll>, ll>p[100];
	for (ll i = 0; i < n; i++) {
		string s;
		ll a;
		cin >> s >> a;
		p[i] = make_pair(make_pair(s, -a),i);
	}
	sort(p, p+n);
	for (ll i = 0; i < n; i++) {
		//cout << p[i].first.first << endl;
		cout << p[i].second + 1 << endl;
	}



}


