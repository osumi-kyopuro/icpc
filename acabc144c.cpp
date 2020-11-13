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
	ll n,x=LLONG_MAX;
	cin >> n;
	for (ll i = 1; i <=sqrt(n); i++) {
		if (n%i == 0) {
			x = min(x, (i + n / i - 2));
			//cout << x << endl;
		}
	}

	cout << x << endl;
}