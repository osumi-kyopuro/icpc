#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	long long n, k,count=0;
	cin >> n >> k;
	vector<long long>a(n);
	vector<long long>b(n*k);
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		b[0] = a[0];
		for (long long j = 0; i*j < b.size(); j++) {
			b[(j+1)*n] = a[i];
		}
	}
	for (long long i = 0; i < k*n; i++) {
		for(long long j = i + 1; j < k*n; j++) {
			if (b[i] > b[j]) {
				count++;
			}
		}
	}
}