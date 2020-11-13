#include<iostream>
#include<vector> 
#include<algorithm>
#include<string>
using namespace std;
int main() {
	long long n, maxp,minp;
	cin >> n;
	vector<long long>r(n);
	for (long long i = 0; i < n; i++) {
		cin >> r[i];
	}
	maxp = -2000000000;
	minp = r[0];
	for (long long i = 0; i < n; i++) {
		maxp = max(maxp, r[i] - minp);
		minp = min(minp, r[i]);
	}
	
	cout << maxp << endl;
}