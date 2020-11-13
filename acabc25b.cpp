#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<cmath>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	vector<string>s(n);
	vector<ll>d(n);
	ll sum=0;
	for (ll i = 0; i < n; i++) {
		cin >> s[i] >> d[i];
	}
	for (ll i = 0; i < n; i++) {
		if (s[i] == "East") {
			if (d[i] < a) {
				sum += a;
			}
			else if (a <= d[i] && d[i] <= b) {
				sum += d[i];
			}
			else {
				sum += b;
			}
		}
		else {
			if (d[i] < a) {
				sum -= a;
			}
			else if (a <= d[i] && d[i] <= b) {
				sum -= d[i];
			}
			else {
				sum -= b;
			}

		}

	}
	if (sum < 0) {
		cout << "West" << ' ' << abs(sum) << endl;
	}
	else if (sum > 0) {
		cout << "East" << ' ' << sum << endl;
	}
	else {
		cout << 0 << endl;
	}




}