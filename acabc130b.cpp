#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int x, n,count=1;
	cin >> n >> x;
	vector<int>l(n);
	vector<int>d(n+1);
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	d[0] = 0;
	for (int i = 1; i < n; i++) {
		d[i] = d[i - 1] + l[i - 1];
		count++;
		d[i + 1] = d[i] + l[i];
		if (d[i + 1] > x&&d[i] <= x) {
			cout << count << endl;
			//cout << d[i] << endl;
			//cout << d[i+1] << endl;
			exit(0);
		}
		if (i==n-1&&d[i + 1] <= x) {
			cout << count + 1 << endl;
		}
	}

}