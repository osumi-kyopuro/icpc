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
ll kaijou(ll t) {
	if (t ==0) {
		return 1;
	}
	else {
		return t * kaijou(t - 1);
	}
}

int main() {
	ll n, k;
	cin >> n >> k;
	if (n > k||k>n) {
		cout << (ll)(k * pow(k - 1, n - 1)) << endl;;
	}
	else {
		cout<<kaijou(k)<<endl;
	}
	
}



