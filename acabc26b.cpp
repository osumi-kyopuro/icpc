#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<cmath>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;

int main() {
	double n,sum=0;
	cin >> n;
	vector<ll>r(n);
	for (ll i = 0; i < n; i++) {
		cin >> r[i];
	}
	sort(r.begin(), r.end(),greater<ll>());
	sum += r[0] *r[0]* PI;
	for (ll i = 1; i <n; i++) {
		if (i % 2 == 0) {
			sum +=r[i]*r[i]*PI;
		}
		else {
			sum -= r[i] * r[i] * PI;
		}

		
	}
	printf("%.9f\n", sum);
}