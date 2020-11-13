#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	long long big=0,n,count=0;
	cin >> n;
	vector<long long>h(n);
	for (long long i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (long long i = 0; i < n-1; i++) {
		if (h[i + 1] - h[i] > 0) {
			if (big < count) {
				big = count;
			}
			count = 0;
		}
		else {
			count++;
		}
	}
	cout << max(count,big) << endl;
}