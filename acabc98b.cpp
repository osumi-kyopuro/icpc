#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
#define ll long long
using namespace std;

int main() {
	ll n,saidai=0;
	string s;
	cin >> n >> s;
	for (ll kyoukai = 1; kyoukai < n - 1; kyoukai++) {
		vector<ll>big(n, 0);
		vector<ll>countX(26, 0);
		vector<ll> countY(26, 0);
		for (ll i = 0; i < kyoukai; i++) {
			countX[s[i] - 'a']++;
		}
		for (ll i = kyoukai; i < n; i++) {
			countY[s[i] - 'a']++;
		}
		for (ll i = 0; i < 26; i++) {
			if (countX[i] > 0 && countY[i] > 0) {
				big[kyoukai]++;
			}
		}
		saidai = max(big[kyoukai], saidai);
		//cout << kyoukai<<" "<<saidai << endl;
	}

	cout << saidai << endl;


}