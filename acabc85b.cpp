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
	ll n;
	cin >> n;
	set<ll>s;
	
	for (ll i =0; i < n; i ++ ) {
		ll a;
		cin >> a;
		s.insert(a);
	}
	cout << s.size() << endl;
}