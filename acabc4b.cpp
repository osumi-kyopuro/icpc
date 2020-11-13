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
	vector<vector<char>>s(4,vector<char>(4));
	for (ll i = 0; i < 4; i++) {
		for (ll j = 0; j < 4; j++) {
			cin >> s[i][j];
		}
	}
	for (ll i = 3; i >=0; i--) {
		for (ll j = 3; j >=0; j--) {
			cout << s[i][j]<<' ' ;
		}
		cout << endl;
	}

}
