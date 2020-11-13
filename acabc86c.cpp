#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;
int main() {
	long long n;
	long long dt, dist;
	cin >> n;
	vector<long long>t(n+1);
	vector<long long>x(n+1);
	vector<long long>y(n+1);
	t[0] = 0;
	x[0] = 0;
	y[0] = 0;
	for (long long i = 1; i < n+1; i++) {
		cin >> t[i] >> x[i] >> y[i];
	}
	bool flag=true;
	for (long long i = 0; i < n; i++) {
		dt = t[i + 1] - t[i];
		dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
		if (dist % 2 != dt%2||dist>dt) {
			flag = false;
		}

	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}


}