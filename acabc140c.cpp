#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n,sum=0,s;
	cin >> n;
	vector<int>b(n-1);
	vector<int>a(n);
	for (int i = 0; i < n-1; i++) {
		cin >> b[i];
	}
	a[0] = b[0];
	for (int i = 1; i < n-1; i++) {
		a[i] = min(b[i-1], b[i]);
		sum += a[i];
	}
	sum += b[0];
	sum += b[n - 2];
	cout << sum << endl;

}