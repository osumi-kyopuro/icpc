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
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll i=0,count=1;
	while (a[i] != 2) {
		i = a[i] - 1;
		count++;
		if (count == a.size()) {
			cout << "-1" << endl;
			exit(0);
		}
	}
	cout << count << endl;
}

