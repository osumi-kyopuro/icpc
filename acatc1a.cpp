#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>
#include<set>
#include<map>
#include<stack>
#define ll long long
using namespace std;

int main() {
	ll h, w, gx, gy;
	cin >> h >> w;
	vector<ll>dy = { 1,0,-1,0 };
	vector<ll>dx = { 0,1,0,-1 };
	vector<vector<char>>c(h, vector<char>(w));
	vector<vector<ll>>k(h, vector<ll>(w, -1));
	stack<pair<ll, ll>>st;
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			cin >> c[i][j];
			if (c[i][j] == '.') {
				k[i][j]++;
			}
			else if (c[i][j] == 's') {
				st.push(make_pair(i, j));
				k[i][j] = 1;
			}
			else if (c[i][j] == 'g') {
				k[i][j]++;
				gy = i;
				gx = j;
			}
		}
	}
	while (!st.empty()) {
		pair<ll, ll>p = st.top();
		bool flag = false;
		for (ll i = 0; i < 4; i++) {
			ll ny = p.first + dy[i];
			ll nx = p.second + dx[i];
			if (ny >= 0 && ny <h && nx >= 0 && nx < w && k[ny][nx] == 0) {
				st.push(make_pair(ny, nx));
				k[ny][nx] = 1;
				flag = true;
			}

		}
		if (flag == false) {
			st.pop();
		}

	}
	if (k[gy][gx]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}


}
