#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;
int main() {
	long long n,k=0;
	cin >> n;
	vector<int>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		if (i + 1 == vec[i]) {
			k++;
		}
	}
	if (n - 2 <= k) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	



}