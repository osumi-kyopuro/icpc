#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<cmath>
#define ll long long
using namespace std;

int main() {
	ll n,sum=0;
	cin >> n;
	for (ll i = 2; i <= n; i++) {
		sum += 1 + i;
	}
	cout << sum << endl;

}
