#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<climits>
#include<cstdlib>
#define ll long long
using namespace std;
int main() {
	ll sum=0,n;
	string s;
	cin >> s;
	n = stoi(s);//•¶š—ñ‚©‚ç”’l‚É•ÏŠ·
	for (ll i = 0; i < s.size(); i++) {
		sum += s[i]-'0';
	}
	if (n%sum == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}