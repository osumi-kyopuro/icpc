#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long l, r;
	cin >> l >> r;
	long long a = (l*r) % 2019;
	if (r-l+1>=2019) {
		cout << "0" << endl;
	}
	else {
		for (long long i = l; i <= r; i++) {
			for (long long j = i + 1; j <= r; j++) {
				a = min(a, (i*j) % 2019);
			}
		}
		cout << a << endl;
	}

}
