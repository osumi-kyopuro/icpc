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
	vector<string>s(h);
	for (ll i = 0; i < h; i++) {
		cin >> s[i];
	}
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			if (i == 0) {
				if (j == 0) {
					if (s[i][j] == '#' 
						&& (s[i][j] != s[i + 1][j] &&
						s[i][j] != s[i][j + 1])) {
						cout << "No" << endl;
						exit(0);
					}
				}
				else if (j==w-1) {
					if (s[i][j] == '#'
						&& (s[i][j] != s[i + 1][j] &&
							s[i][j - 1] != s[i][j])) {
						cout << "No" << endl;
						exit(0);
					}
				}
				else {
					if (s[i][j] == '#' 
						&& (s[i][j] != s[i + 1][j] &&
						s[i][j] != s[i][j + 1] &&
						s[i][j - 1] != s[i][j])) {
						cout << "No" << endl;
						exit(0);
					}

				}
					
			}
			else if (i == h - 1) {
				if (j == 0) {
					if (s[i][j] == '#'
						&& (s[i][j] != s[i - 1][j] &&
							s[i][j] != s[i][j + 1])) {
						cout << "No" << endl;
						exit(0);
					}
				}
				else if (j == w - 1) {
					if (s[i][j] == '#'
						&& (s[i][j] != s[i - 1][j] &&
							s[i][j - 1] != s[i][j])) {
						cout << "No" << endl;
						exit(0);
					}
				}
				else {
					if (s[i][j] == '#'
						&& (s[i][j] != s[i - 1][j] &&
							s[i][j] != s[i][j + 1] &&
							s[i][j - 1] != s[i][j])) {
						cout << "No" << endl;
						exit(0);
					}
				}

			

			}
			else {
				if (j == 0) {
					if (s[i][j] == '#'
						&& (s[i][j] != s[i + 1][j] &&
							s[i-1][j] != s[i][j]&&
							s[i][j + 1] != s[i][j])) {
						cout << "No" << endl;
						exit(0);
					}


				}
				else if (j == w - 1) {
					if (s[i][j] == '#'
						&& (s[i][j] != s[i + 1][j] &&
							s[i - 1][j] != s[i][j] &&
							s[i][j - 1] != s[i][j])) {
						cout << "No" << endl;
						exit(0);
					}
				}
				else {
					if (s[i][j] == '#'
						&& (s[i - 1][j] != s[i][j] &&
							s[i][j] != s[i + 1][j] &&
							s[i][j] != s[i][j + 1] &&
							s[i][j - 1] != s[i][j])) {
						cout << "No" << endl;
						exit(0);
					}

				}
			}
			
		}
	}
	cout << "Yes" << endl;
}

