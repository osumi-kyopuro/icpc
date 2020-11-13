#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
int main() { 
	long long  n;
	cin >> n;
	vector<long long >a(n);
	vector<long long >a2(n);
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	a2 = a;
	sort(a2.begin(), a2.end());
	for (long long i = 0; i < n; i++) {
		if (a[i] == a2[n-1]) {
			cout << a2[n-2] << endl;
		}
		else {
			cout << a2[n-1] << endl;
		}
		
	}
}