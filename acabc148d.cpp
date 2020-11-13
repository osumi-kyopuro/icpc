#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<climits>
#include<set>
#include<map>
#define ll long long
using namespace std;

int main() {
	ll n, count = 0, s, k = 1;
	cin >> n;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll flag = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] != 1) {
			flag++;
		}
	}
	if (flag == n) {
		cout << -1 << endl;
		exit(0);
	}

	for (ll i = 0; i <n; i++) {
		if (a[i] == 1) {
			count += i;
			s = i;
			k++;
			break;
		}
	}
	for (ll i = s; i<n; i++) {
		if (a[i] == k) {
			count += i - s - 1;
			s = i;
			k++;
		}
		else if (i == n - 1) {
			count += n - 1 - s;
		}
	}
	cout << count << endl;


}

