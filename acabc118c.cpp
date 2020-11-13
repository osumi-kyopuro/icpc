#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n,x,y;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}
	for (int i = 1; i < n; i++) {
		x = max(a[i-1], a[i]);
		y = min(a[i], a[i-1]);
		int r = x % y;
		while (r != 0) {
			x = y;
			y = r;
			r = x % y;
		}
		a[i] = y;
	}

	cout << y<< endl;
}