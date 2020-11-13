#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n, m, c,sum=0,count=0;
	cin >> n >> m >> c;
	vector<int>b(m);
	int a[20][20];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < m; j++) {
			sum += a[i][j] * b[j];
			if (j == m - 1) {
				sum += c;
				if (sum > 0) {
					count++;
				}
			}
		}
	}
	cout << count << endl;

}