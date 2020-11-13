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
	ll n,hk=0,ok=0,sum=0,t;
	cin >> n;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (ll i = 0; i < n;i++) {
		if (i<n-1&&a[i] != a[i + 1]) {
			ok = i;
			t = ok - hk + 1;
			sum += t-1;
			hk = ok + 1;
		}
		else if (i == n - 1) {
			ok = i;
			t = ok - hk + 1;
			sum += t - 1;
		}
	}
	cout << sum << endl;
}
