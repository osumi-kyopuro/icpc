#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n, count = 0, k = 1;
	cin >> n;
	vector<int>h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i < n; i++) {
		count = 0;
		for (int j = 0; j < i; j++) {
			if (h[i] >= h[j]) {
				//cout << h[j] << endl;
				count++;
			}
			if (count == i) {
				k++;
				count = 0;
			}
		}
	}
	cout << k << endl;

}