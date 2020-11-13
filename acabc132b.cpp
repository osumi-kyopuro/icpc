#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int n,count=0;
	cin >> n;
	vector<int>p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i < n-1; i++) {
		if (p[i] > min(p[i + 1], p[i-1])&&p[i]<max(p[i+1],p[i-1])) {
			count++;
			//cout << p[i] << endl;
		}
	}
	cout << count << endl;
}