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
	ll n,x=0;
	cin >> n;
	vector<string>s(n);
	map<string, ll>m;
	for (ll i = 0; i < n; i++) {
		string o;
		cin >> o;
		m[o]++;
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		if (i->second > x) {
			x = max(x, i->second);
		}
	}
	bool flag = true;
	for (auto i = m.begin(); i!=m.end();i++) {
		if (flag==true&&x == i->second) {
			cout << i->first << endl;
			flag = false;
		}
	}
	
}
