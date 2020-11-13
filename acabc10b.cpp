#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#define ll long long
using namespace std;

int main() {
	ll n,sum=0;
	cin >> n;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];	
		if (a[i] >= 9) {
			sum += a[i] - 9;
		}
		else if (a[i] >= 7) {
			sum += a[i] - 7;
			//cout << sum << endl;
		}
		else if (a[i] >= 3) {
			sum += a[i] - 3;
			//cout << sum << endl;
		}
		else if (a[i] >= 1) {
			sum += a[i] - 1;
			//cout << sum << endl;
		}
	}
	cout << sum << endl;


}