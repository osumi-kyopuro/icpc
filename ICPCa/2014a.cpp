#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	while (true) {
		int x, y, s;
		double d1, d2;
		double p1,p2;
		double sum=0;
		double k1, k2;
		cin >> x >> y >> s;
		if (x == 0 && y == 0 && s == 0) {
			break;
		}
		d1 = 0.01;
		d2 = double(s) - 0.01;
		while (d2>0) {
			p1 =double( 100 * (d1) )/ double(100.000000 + x);
			p2 = double(100 * (d2)) / double(100.000000 + x);
			k1 = double(p1 * (100 + y)) / double(100.000);
			k2 = double (p2 * (100 + y)) / double(100.000);
			if (k1 + k2 > sum) {
				//cout << p1 << endl;
				//cout << p2 << endl;
				//cout << k1 << endl;
				//cout << k2 << endl;
				sum = k1 + k2;
				//cout << sum << endl;
			}
			d1+=0.01;
			d2-=0.01;
		}
		cout << (int)(sum) << endl;
	}
}