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
	ll a, b, x;
	cin >> a >> b >> x;
	if (a == 0) {
		cout << (b) / x - (max(a - 1, 0LL)) / x+1 << endl;
	}
	else {
		cout << (b) / x - (max(a - 1, 0LL)) / x << endl;
	}
	
}