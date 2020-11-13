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
	ll n,count=0;
	cin >> n;
	if (n % 2 != 0) {
		cout << 0 << endl;
		return 0;
	}
	for (ll i = 10; i <= n; i*=5) {
		count += n / (i);
	}
	cout << count << endl;

}
