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
	ll h, w, k,p=0;
	cin >> h >> w >> k;
	vector<string>s(h);
	vector<vector<ll>>count(h,vector<ll>(w));
	for (ll i = 0; i < h; i++) {
		cin >> s[i];
	}
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				p++;
				count[i][j]+=p;
			}
		}
	}
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			cout << count[i][j];
		}
		cout << endl;
	}


}
