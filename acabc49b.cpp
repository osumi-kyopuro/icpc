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
	vector<string>c(h);
	for (ll i = 0; i <h; i++) {
		cin >> c[i];
	}
	for (ll i = 0; i <c.size(); i++) {
		for (ll k = 0; k < 2; k++) {
			for (ll j = 0; j <c[i].size(); j++) {
				cout << c[i][j];
			}
			cout<<endl;
		}
	}
}

