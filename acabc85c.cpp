#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	long long n, Y,x,y,z;
	cin >> n >> Y;
	for (z= 0; z <= n; z++) {
		for (y = 0; y <= n-z; y++) {
			x = n - z - y;
			if (10000 * x + 5000 * y + 1000 * z == Y ) {
				cout << x << " " << y << " " << z << endl;
				exit(0);
			}
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
}