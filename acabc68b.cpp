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
	vector<ll>a(n + 2), count(n + 2,0);
	for (ll i = 1; i <= n; i++) {
		a[i] = i;
		//cout << a[i] << endl;
	}
	for (ll i = 1; i <= n; i++) {
		while (a[i] %2 != 1) {
			a[i] /= 2;
			count[i]++;
		}
		//cout << count[i] << endl;
	}
	ll max = 0,maxi=0;
	for (ll i = 1; i <= n; i++) {
		if (count[i] >= max) {
			maxi=i;
			max = count[i];
		}
	}
	cout << maxi << endl;
	
}
