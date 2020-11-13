#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<cmath>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;

int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	if (s.size() % 2 != 1) {
		cout << -1 << endl;
		exit(0);
	}
	ll kaisuu = s.size() / 2 ;
	ll kaisuu2 = kaisuu;
	for (ll i = 0; i<=s.size()/2; i++) {
		if (kaisuu2 % 3 == 0&&s[i]!='b'&&s[s.size()-1-i]!='b') {
			cout << -1 << endl;
			exit(0);
		}
		else if (kaisuu2 % 3 == 1 && s[i] != 'a'&&s[s.size()-1-i] != 'c') {
			cout << -1 << endl;
			exit(0);
		}
		else if(kaisuu2%3==2&&s[i]!='c'&&s[s.size()-1-i]!='a'){
			cout << -1 << endl;
			exit(0);
		}
		kaisuu2--;
	}
	cout << kaisuu << endl;
}