#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int>b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = i+1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(b[j], b[j + 1]);
				swap(a[j], a[j + 1]);
				//cout << b[j] << endl;
				//cout << b[j + 1] << endl;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << b[i]<<" ";
	}
	cout << endl;


}