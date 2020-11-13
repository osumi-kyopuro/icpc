#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	long long n, m, sum, small = 0, big;
	double ave;
	cin >> n >> m;
	vector<long long>l(m);
	vector<long long>r(m);
	for (long long i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
	}
	big = r[0];

	for (long long i = 0; i < m; i++) {
		if (small < l[i]) {
			small = l[i];
		}
		if (big > r[i]) {
			big = r[i];
		}
	}
	if (big < small) {
		cout << "0" << endl;
	}
	else {
		cout << big - small + 1 << endl;

	}
}