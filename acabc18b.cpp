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
	string s;
	cin >> s;
	ll n;
	cin >> n;
	vector<ll>l(n), r(n);
	for (ll i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		reverse(s.begin() + l[i] - 1, s.begin() + r[i]);
		//cout << s << endl;
	}
	cout << s << endl;

}
