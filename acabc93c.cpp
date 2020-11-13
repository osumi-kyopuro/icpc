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
	vector<ll>a(3);
	ll count = 0;
	for (ll i = 0; i < 3; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	while (a[0]!=a[1]||a[1]!=a[2]||a[0]!=a[2]) {
		if (a[2] - a[1] >= 1) {
			a[1]++;
			a[0]++;
		}
		else {
			if (a[2] - a[0] >= 2) {
				a[0]+=2;
			}
			else if (a[2] - a[0] < 2) {
				a[2]++;
				a[1]++;
			}
		}
		count++;
	}
	cout << count << endl;


}
