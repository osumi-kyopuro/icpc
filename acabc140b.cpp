#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n,sum=0;
	cin >> n;
	vector<int>a(n);
	vector<int>b(n);
	vector<int>c(n-1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n-1; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		sum += b[i];
		//cout << "cc" << endl;
	}
	for (int i = 1; i < n; i++) {
		//cout << "aaa" << endl;
		if (a[i-1]+1==a[i] ) {
			sum += c[(a[i-1])-1];
			//cout << "aa" << endl;
		}
		
	}
	cout << sum << endl;

}