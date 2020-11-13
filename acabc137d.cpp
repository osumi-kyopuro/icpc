#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int gcd(int x, int y) {
	int z;
	while (x%y != 0) {
		z = x % y;
		x = y;
		y = z;

	}
	return y;
}

int main() {
	int a, b, c,d,nac,nbc,nabc, nad, nbd, nabd,answer;
	cin >> a >> b >> c >> d;
	nac = (a-1) / c;
	nbc = b / c;
	nabc = nbc - nac;
	nad = (a - 1) / d;
	nbd = b / d;
	nabd = nbd - nad;
	if (d != 0) {
		int e = c * d / gcd(c, d);

		int nae = (a - 1) / e;
		int nbe = b / e;
		int nabe = nbe - nae;

		answer = b - a + 1 - (nabc + nabd - nabe);
	}
	else {
		 answer = b - a + 1 - (nabc + nabd);
	}

	cout << answer << endl;

	


}
