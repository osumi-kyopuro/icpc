#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	double n, k,s=0,t;
	cin >> n >> k;
	for (double i = 1; i <= n;i++) {
		t = 0;
		while (k > i*pow(2.0, t)) {
			t++;
		}
		s += (1 / n) * pow((1 / 2.0), t);
	}
	
	printf("%.10f", s);
}