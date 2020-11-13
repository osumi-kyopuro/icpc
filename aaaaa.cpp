#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#define ll long long
using namespace std;

int main() {
	ll n, q,kosu=0;
	string s;
	cin >> n >> q >> s;
	vector<ll>l(q);
	vector<ll>r(q);
	vector<ll>count(n,0);
	for (ll j = 0; j < q; j++) {
		cin >> l[j] >> r[j];
	}
	for (ll i =1; i < n; i++) {
		if (s[i-1] == 'A'&&s[i] == 'C') {
			kosu++;
		}
		count[i] = kosu;
		//cout << kosu;
	}
	//cout << endl;
	for (ll i = 0; i < q; i++) {
		cout << count[r[i]-1] - count[l[i]-1] << endl;
	}


}