#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int n;
	double sum=0;
	cin >> n;
	vector<double>x(n);
	vector<string>u(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		cin >> u[i];
		if (u[i] == "BTC") {
			x[i]= 380000 * x[i];
		}
		sum += x[i];

	}
	printf("%.9f", sum);

}