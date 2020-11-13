#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<climits>
#define ll long long
using namespace std;
int main() {
	ll n, k,count=0;
	cin >> n >> k;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (ll i = k; i <= n; i += k-1) {
		if (n == i) {
			count++;
			//cout << i << endl;
			break;
		}
		count++;
		//cout << i  << endl;
		if (i + k - 1 > n) {
			count++;
			break;
		}
	}
	cout << count << endl;
	
}