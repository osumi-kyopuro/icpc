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
	ll n;
	cin >> n;
	vector<ll>l(n+1);
	l[0] = 2;
	l[1] = 1;
	for (ll i = 2; i <= n; i++) {
		l[i] = l[i - 1] + l[i - 2];
	}
	cout << l[n] << endl;
}