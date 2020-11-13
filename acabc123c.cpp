#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	long long n, a, b, c, d, e, t=0;
	long long p1, p2 = 0, p3 = 0, p4 = 0, p5 = 0, p6 = 0;
	cin >> n>>a >> b >> c >> d >> e;
	p1 = n;
	while (p6!=n) {
		if (p5>0 && p6 < n) {
			p6 += min(e, p5);
			p5 -= min(e, p5);
			//cout << p5 << endl;
			//cout << p6 << endl;
			//cout << t << endl;
		}
		if (p4>0 && p5 + p6 < n) {
			p5 += min(d, p4);
			p4 -= min(d, p4);
		}
		if (p3>0 && p4 + p5 + p6 < n) {
			p4 += min(c, p3);
			p3 -= min(c, p3);
		}
		if (p2>0 && p3 + p4 + p5 + p6 < n) {
			p3 += min(b, p2);
			p2 -= min(b, p2);
		}
		if (p1>0&&p2 + p3 + p4 + p5 + p6 < n) {
			p2 += min(a, p1);
			p1 -= min(a, p1);
		}
		
		t++;

	}
	cout << t << endl;

}