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
	ll n,p=1;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		p *= i;
		p = p % (1000000000 + 7);
	}
	cout << p << endl;
}

