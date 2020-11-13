#include<iostream>2
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
	ll n,x=LLONG_MAX;
	cin >> n;
	for (ll k = n; k >= 1; k--) {
		for (ll i = 1; i <= sqrt(n); i++) {
				if (i*(k/i) == k) {
					x = min(max(i,(k/i)) - min(i,(k/i)) + (n - k),x);
					//cout << x << endl;

				}
			
		}
	}
	cout << x << endl;
}