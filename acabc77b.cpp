#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<climits>
#include<map>
#define ll long long
using namespace std;
int main() {
	ll n,x;
	cin >> n;
	for (ll i = 0; i*i <= n;i++) {
		x = i * i;
	}
	cout << x << endl;
}