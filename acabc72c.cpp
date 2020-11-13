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
	ll n;
	cin >> n;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll left = 0;
	ll right = 0;
	ll ans= 1;
	while (right < n-1) {
		if (a[right+1] - a[left] <= 2) {
			right++;
		}
		else {
			left++;
		}
		ans = max(ans, right - left+1);
	}

	cout << ans << endl;
}
