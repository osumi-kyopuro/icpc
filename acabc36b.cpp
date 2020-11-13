#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<cmath>
#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<string>s(n);
	for (ll i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = n-1; j >=0; j--) {
			cout<< s[j][i];
		}
		cout << endl;
	}
}
