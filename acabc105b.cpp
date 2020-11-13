#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int main() {
	int n;
	bool flag = false;
	cin >> n;
	for (int i = 0; i <= n / 4; i++) {
		for (int j = 0; j <= n / 7; j++) {
			if (i * 4 + j * 7 == n) {
				flag = true;
			}
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}