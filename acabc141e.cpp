#include<iostream>
#include<string>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool rk(string t, string p) {
	int  k=1000007, m=1000000007;
	long long ht = 0;
	long long  po = 1;
	for (int i = 0; i < p.size();i++) {
		po *= k;
		po %= m;
	}
	po %= m;
	for (int i = 0; i < p.size();i++) {
		ht *= k;
		ht += t[i];
		ht %= m;
	}
	long long hp = 0;
	for (int i = 0; i < p.size(); i++) {
		hp *= k;
		hp += p[i];
		hp %= m;
	}
	for (int i = 0; i < t.size()-p.size()+1;i++) {
		if (hp==ht) {
			if (t.substr(i,p.size())==p) {
				return true;
			}
		}
		if (i+p.size()<t.size()) {
			ht *= k;
			ht -= t[i] * po;
			ht += t[i + p.size()];
			ht %= m;
			if (ht < 0) {
				ht += m;
			}
		}
	}
	return false;
}

bool calc(string s,int n) {
	if (n==0) {
		return true;
	}
	for (int i = 0; i+n*2 < s.size();i++) {
		string ss1 = s.substr(i, n);
		string ss2 = s.substr(i+n);
		if (rk(ss2, ss1)) {
			return true;
		}
		
	}
	return false;
	
}

int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	int left = 0;
	int right = n/2+1;
	while (left < right) {
		int i = left + (right - left) / 2;
		if (calc(s, i)) {
			left = i + 1;
		}
		else {
			right = i;
		}
	}
	cout << left-1 << endl;
	system("pause");
}
