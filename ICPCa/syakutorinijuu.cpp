#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main() {
	int n, q;
	cin >> n >> q;
	vector<long long>a(n);
	for (int i = 0; i < n; i++)  
		cin >> a.at(i);

	for (int j = 0; j < q; j++) {
		long long x;
		cin >> x;
		long long res = 0;

		int right = 0;
		long long sum = 0;
		for (int left = 0; left < n; left++) {

			while (right < n&&sum + a.at(right) <= x) {
				sum += a.at(right);
				right++;
			}
			res += (right - left);

			if (right == left) {
				right++;
			}
			else {
				sum -= a.at(left);
			}
		}
		cout << res << endl;
	}
}