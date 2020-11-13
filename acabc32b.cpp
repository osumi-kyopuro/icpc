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
	string s;
	cin >> s;
	ll k;
	cin >> k;
	vector<string>x(s.size());
	if (s.size() < k) {
		cout << '0' << endl;
	}
	else {
		for (ll i = 0; i < s.size(); i++) {
			x[i] = s.substr(i, k);
		}

		set<string>a;
		for (ll i = 0; i < x.size()-k+1; i++) {
			a.insert(x[i]);
			//cout << x[i] << endl;
		}
		cout << a.size() << endl;
	}
}