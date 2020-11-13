#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<queue>
#define ll long long
using namespace std;
int main() {
	ll n,x=LLONG_MAX,n2;
	cin >> n;
	n2 = n;
	for (ll i = 1; i <= n; i++) {
		for (ll j = n2; j >= i + 1; j--) {
			if (i*j == n) {
				x = min(x, i - 1 + j- 1);
				n2 = j;
			}
		}
	}
	
	cout << x << endl;
}