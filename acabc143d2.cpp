#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int main() {
	long long n, count = 0;
	cin >> n;
	vector<long long>l(n);
	for (long long i = 0; i < n; i++) {
		cin >> l[i];
	}
	sort(l.begin(), l.end());
	for (long long mid = n - 1; mid >= 0; mid--) {
		for (long long low = mid - 1; low >= 0; low--) {
			auto itr = lower_bound(l.begin(), l.end(), l[mid] + l[low]);
			long long ng = distance(itr, l.end());
			count += (n - 1 - mid) - ng;
		}
	}
	cout << count<< endl;

}