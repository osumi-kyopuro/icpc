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
	string w;
	cin >> w;
	vector<ll>a(26, 0);
	for (ll i = 0; i < w.size(); i++) {
		a[w[i]-'a']++;
	}
	for (ll i = 0; i < 26; i++) {
		if (a[i] !=0) {
			if (a[i] % 2 != 0) {
				cout << "No" << endl;
				exit(0);
			}
		}
	}
	cout << "Yes" << endl;
}



