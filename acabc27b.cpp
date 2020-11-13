#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<map>
#define ll long long
using namespace std;


int main() {
	ll n, sum = 0, k = 0;
	cin >> n;
	vector<ll>a(n), msum(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		msum[i] = sum;
	}
	if (sum%n != 0) {
		cout << -1 << endl;
		exit(0);
	}
	for (ll i = 0; i < n - 1; i++) {
		if (msum[i] != sum / n * (i + 1)) {
			k++;
		}
	}
	cout << k << endl;
}
