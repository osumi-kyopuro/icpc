#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
#define ll long long
using namespace std;
bool ls(ll c,string s) {
	ll x=0;
	for (ll i = 0; i < s.size()/2; i++) {
		for (ll j = i + 1; j < s.size(); j++) {
			if (s[i] == s[j]) {

			}
		}
	}
}
int main() {
	ll n;
	string s;
	cin >> n;
	cin >> s;
	ll left=0, right=5000;
	while (left <= right) {
		if (ls(left + (right - left) / 2),s) {
			right = left + (right-left) / 2 - 1;

		}
		else {
			left= left + (right-left) / 2 +1;
		}
	}

}