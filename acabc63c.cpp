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
	ll n, sum=0,min=0;
	cin >> n;
	vector<ll>s(n);

	for (ll i = 0; i < n; i++) {
		cin >> s[i];
		sum += s[i];
	}
	if (sum % 10 != 0) {
		cout << sum << endl;
		exit(0);
	}
	sort(s.begin(), s.end());
	for (ll i = 0; i < n; i++) {
		if (s[i]%10!=0) {
			min = s[i];
			cout << sum - min << endl;
			exit(0);
		}
	}
	cout << 0 << endl;
	

}
