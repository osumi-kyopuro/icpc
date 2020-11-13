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
	ll h, w;
	cin >> h >> w;
	vector<string>s(h);
	ll a[50][50] = {0};
	for (ll i = 0; i < h; i++) {
		cin >> s[i];
	}
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			for (ll k = -1; k <= 1; k++) {
				if (i == 0&&k==-1||i==h-1&&k==1) {
					continue;
				}
				for (ll l = -1; l <= 1; l++) {
					if (j == 0&&l==-1||j==w-1&&l==1) {
						continue;
					}
					else if (s[i + k][j + l] == '#') {
						a[i][j]++;
					}
				}
			}
		}
	}
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				cout << '#';
			}
			else {
				cout << a[i][j];
			}
		}
		cout << endl;
	}




}
