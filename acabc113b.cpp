#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	double n,t,a,ix;
	double m = 100000;
	cin >> n >> t >> a;
	vector<int>h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		if (abs(a - (t - h[i] * 0.006)) < m) {
			m = min(m, abs(a - (t - h[i] * 0.006)));
			ix = i;
		}
	}
	cout <<(int) ix+1 << endl;
}
