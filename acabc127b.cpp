#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int x, r, d;
	cin >> r >> d >> x;
	for (int i = 0; i < 10; i++) {
		x = r * x - d;
		cout << x << endl;
	}
}