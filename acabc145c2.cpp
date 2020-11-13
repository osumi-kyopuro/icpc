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
		return n * factorial(n);
	}
		
	else {
		return 1;
	}
}
double dist(vector<ll> x,vector<ll> y,int from ,int to) {
	return sqrt(pow(x[from]-x[to],2)+pow(y[from]-y[to],2));
}
double keisan(vector<ll>x, vector<ll>y,
	vector<bool>a, int from) {
	double res = 0;
	int count = 0;
	for (int i = 0; i < a.size(); i++) {
		if (!a[i]) {
			a[i] = true;
			res += keisan(x,y,a,i)+dist(x,y,from,i);
			a[i] = false;
			count++;
		}
	}
	if (count!=0) {
		return res/count;
	}
	else {
		return 0;
	}
}


int main() {
	double n, sum = 0;
	cin >> n;
	vector<ll>x(n), y(n);
	for (ll i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	/*
	for (ll i = 0; i < n - 1; i++) {
		for (ll j = i + 1; j < n; j++) {
			sum += sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
		}
	}
	printf("%.9f\n", sum * 2 * factorial(n - 1) / factorial(n));
	*/
	double ans = 0;
	vector<bool> a(n,false);
	for (int i = 0; i < n;i++) {
		a[i] = true;
		ans += keisan(x,y,a,i);
		a[i] = false;
	}
	printf("%.9f\n",ans/n);
	cout<<factorial(n)<<endl;
}