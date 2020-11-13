#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<climits>
#include<map>
#define ll long long
using namespace std;
int main() {
	ll n,m;
	cin >> n;
	map<string,int>mp;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[s]++;
	}
	cin >> m;
	for (ll i = 0; i < m; i++) {
		string s;
		cin >> s;
		mp[s]--;
	}
	ll ans = 0;
	vector<ll>::iterator it;
	string s;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		ans = max((int)(ans), it->second);
	}
	cout << ans << endl;


}
