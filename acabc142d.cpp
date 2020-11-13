#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#define ll long long
using namespace std;
ll gcd(ll a, ll b);
ll sosuu(ll x);
int main() {
	ll a, b,r,tmp;
	cin >> a >> b;

	b = gcd(a, b);
	cout <<sosuu(20) << endl;



}


/* ユークリッドの互除法 */
ll gcd(ll a, ll b) {
	ll r;
	r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
/*xの素因数の種類*/
ll sosuu(ll x) {
	ll b = x;
	ll ans=0;
	for (ll i = 2; i*i <= x; i++) {
		if (b%i == 0) {
			while (b%i == 0) {
				b = b / i;
			}
			ans++;
		}
	}
	if (b != 1) {
		ans++;
	}
	return ans;
}

