#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main() {
	int n,zen=0;
	cin >> n;
	vector<int>d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			zen += d[i] * d[j];
		}
	}
	cout << zen << endl;
}