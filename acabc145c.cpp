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
ll factorial(ll n) {
	if (n > 0) {
		return n * factorial(n - 1);
	}
	else {
		return 1;
	}
}


int main() {
	double n,sum=0;
	cin >> n;
	vector<ll>x(n), y(n);
	for (ll i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (ll i = 0; i < n-1; i++) {
		for (ll j = i + 1; j < n; j++) {
			sum +=sqrt(pow(x[i] - x[j], 2)+pow(y[i]-y[j],2));
		}
	}
	printf("%.9f\n", sum*2*factorial(n-1) / factorial(n));

}
