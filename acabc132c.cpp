#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	long long n,k;
	cin >> n;
	vector<long long>d(n);
	for (long long i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	k = d[n / 2] - d[n / 2 - 1];
	cout << k << endl;
} 