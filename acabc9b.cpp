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
	ll n, m = 0, kotae = 0;
	cin >> n;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > m) {
			kotae = m;
			m= a[i];
		}
		else if(a[i]!=m){
			kotae = max(kotae, a[i]);
		}

	}
	cout << kotae << endl;

}
