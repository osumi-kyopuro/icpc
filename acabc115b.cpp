#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n,big,flag=0,sum=0;
	cin >> n;
	vector<int>p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	big = p[0];
	for (int i = 0; i < n; i++) {
		big = max(big, p[i]);
	}
	for (int i = 0; i < n; i++) {
		if (big == p[i] && flag == 0) {
			flag++;
			sum += big / 2;
		}
		else {
			sum += p[i];
		}
	}
	cout << sum << endl;
	
}