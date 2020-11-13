#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<climits>
#include<set>
#include<map>
#define ll long long
using namespace std;

int main() {
	ll h, w;
	cin >> h >> w;
	vector <vector<char>>s(h + 2, vector<char>(w + 2));
	vector <vector<ll>>x(h + 2, vector<ll>(w + 2,0));
	for (ll i = 1; i <= h; i++) {
		for (ll j = 1; j <= w; j++) {
			cin >> s[i][j];
		}
	}
	for (ll i = 1; i <= h; i++) {
		for (ll j = 1; j <= w; j++) {
			if (s[i][j] == '#') {
				x[i][j]++;
			}
		}
	}
	for (ll i = 1; i <= h; i++) {
		for (ll j = 1; j <= w; j++) {
			if (s[i][j] == '#'&&
				x[i-1][j]+x[i+1][j]+x[i][j-1]+x[i][j+1]==0){
				cout << "No" << endl;
				exit(0);
			}
		}
	}
	cout << "Yes" << endl;
	

	
}

