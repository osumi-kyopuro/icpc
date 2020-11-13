#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int a, b, c,x;
	cin >> a >> b >> c;
	if (c > b/a) {
		x = b / a;
		cout << x << endl;
	}
	else {
		cout << c << endl;
	}


}