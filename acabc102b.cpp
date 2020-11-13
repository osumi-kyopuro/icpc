#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#define ll long long
using namespace std;
int main() {
	ll n;
	cin >> n;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << a[n - 1] - a[0] << endl;

}