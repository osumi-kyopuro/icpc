#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>
#include<set>
#include<map>
#include<stack>
#define ll long long
using namespace std;

int main() {
	ll n, s = 0;
	cin >> n;
	vector<ll>a(n);
	vector<ll>c(9, 0);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] >= 1 && a[i] <= 399) {
			c[0]++;
		}
		else if (a[i] >= 400 && a[i] <= 799) {
			c[1]++;
		}
		else if (a[i] >= 800 && a[i] <= 1199) {
			c[2]++;
		}
		else if (a[i] >= 1200 && a[i] <= 1599) {
			c[3]++;
		}
		else if (a[i] >= 1600 && a[i] <= 1999) {
			c[4]++;
		}
		else if (a[i] >= 2000 && a[i] <= 2399) {
			c[5]++;
		}
		else if (a[i] >= 2400 && a[i] <= 2799) {
			c[6]++;
		}
		else if (a[i] >= 2800 && a[i] <= 3199) {
			c[7]++;
		}
		else {
			c[8]++;
		}


	}
	for (ll i = 0; i <= 7; i++) {
		if (c[i] > 0) {
			s++;
		}
	}
	if (s==0) {
		cout << 1 << " " << s + c[8] << endl;
	}
	else {
		cout << s << " " << s + c[8] << endl;
		
	}




}
