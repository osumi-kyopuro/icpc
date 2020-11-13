#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n, T,s=1000,k=1000,flag=0;
	cin >> n >> T;
	vector<pair<int,int>>p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	//sort(p.begin(), p.end());
	for (int i = 0; i < n; i++) {
		if (p[i].second <= T) {
			s = min(p[i].second, s);
			k = min(p[i].first, k);
			flag = 1;
		}
		else if (i == n - 1&&flag==0) {
			cout << "TLE" << endl;
			exit(0);
		}
	}
	cout << k << endl;

}