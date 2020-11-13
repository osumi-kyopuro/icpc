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

bool search(ll d,ll x,ll a,ll b,vector<ll>s,vector<ll>t) {
	return search1(d, x, a, b, s, t) ||
		search1(d, x, a, b, s, t) ||
		search3(d, x, a, b, s, t) ||
		search5(d, x, a, b, s, t) ||
		search6(d, x, a, b, s, t) ||
		search7(d, x, a, b, s, t) ||
		search8(d, x, a, b, s, t);
}
bool search1(ll d, ll x, ll a, ll b, vector<ll>s, vector<ll>t) {
	return (
		(lower_bound(s.begin(),s.end(), x + d)
		-lower_bound(s.begin(),s.end(), x)>0) &&
		(lower_bound(t.begin(),t.end(), x + d)
		-lower_bound(t.begin(),t.end(), x)>0)
	);
}
bool search3(ll d, ll x, ll a, ll b, vector<ll>s, vector<ll>t) {
	return (
		(lower_bound(s.begin(), s.end(), x-1)
		-lower_bound(s.begin(), s.end(), x-d-1)>0) &&
		(lower_bound(t.begin(), t.end(), x-1)
		-lower_bound(t.begin(), t.end(), x-d-1)>0)
		);
}
bool search5(ll d, ll x, ll a, ll b, vector<ll>s, vector<ll>t) {
	return ();
}
bool search6(ll d, ll x, ll a, ll b, vector<ll>s, vector<ll>t) {

}
bool search7(ll d, ll x, ll a, ll b, vector<ll>s, vector<ll>t) {

}
bool search8(ll d, ll x, ll a, ll b, vector<ll>s, vector<ll>t) {

}

int main() {
	ll a, b, q;
	cin >> a >> b >> q;
	vector<ll>s(a),t(b),x(q);
	for (ll i = 0; i < a; i++) {
		cin >> s[i];
	}
	for (ll i = 0; i < b; i++) {
		cin >> t[i];
	}
	for (ll i = 0; i < q; i++) {
		cin >> x[i];
	}


	for (ll i = 0; i < q; i++) {
		ll left=0,right=20000000000;
		while (left <= right) {
			ll mid = (left + right) / 2;
			if (search(mid,x[i],a,b,s,t)) {
				right = mid-1;
			}
			else {
				left = mid+1;
			}
		}
		cout << left - 1 << endl;
	}

}