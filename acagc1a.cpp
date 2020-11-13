#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<map>
#define ll long long
using namespace std;

int main() {
	string s;
	cin >> s;
	ll sum = 0;
	vector<ll>seiM(s.size() + 1,-1);
	vector<ll>seiA(s.size() + 1, -1);
	vector<ll>sei(s.size() + 1, -1);
	seiM[0] = 0;
	seiA[s.size()] = 0;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			seiM[i + 1] = seiM[i] + 1;
		}
		else {
			seiM[i + 1] = 0;
		}
	}
	for (ll i = s.size()-1; i >= 0; i--) {
		if (s[i] == '>') {
			seiA[i] = seiA[i+1] + 1;
		}
		else {
			seiA[i] = 0;
		}
	}
	for (ll i = 0; i < s.size()+1; i++) {
		sei[i] = max(seiA[i], seiM[i]);
		//cout << seiM[i] <<" ";
		sum += sei[i];
	}
	cout << endl;
	for (ll i = 0; i < s.size() + 1; i++) {
		sei[i] = max(seiA[i], seiM[i]);
		//cout << seiA[i] << " ";
		//sum += sei[i];
	}
	cout << endl;
	for (ll i = 0; i < s.size() + 1; i++) {
		sei[i] = max(seiA[i], seiM[i]);
		//cout << sei[i] << " ";
		//sum += sei[i];
	}
	cout << endl;
	cout << sum << endl;

}
