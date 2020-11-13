#include<iostream>
#include<vector> 
#include<algorithm>
#include<string>
using namespace std;
int main() {
	long long n,s=0;
	cin >> n;
	vector<long long>r(n);
	for (long long i = 0; i < n; i++) {
		cin >> r[i];
	}
	for (long long i = 0; i < n; i++) {
		for (long long j = i+1; j < n; j++) {
			if (s < r[j] - r[i]) {
				s = r[j] - r[i];
			}
		}
	}
	cout << s << endl;
}