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
	ll a, b, c;
	cin >> a >> b >> c;
	if (a == b&&c>0) {
		cout << "NO" << endl;
		exit(0);
	}
	for (ll i = 1; i < 100000000; i++) {
		if ((a*i) % b == c)  {
			cout << "YES" << endl;
			exit(0);
		}
	}
	cout << "NO" << endl;
}

