#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<cmath>
#define ll long long
using namespace std;

int main() {
	ll n;
	double m, x;
	cin >> n >> m;
	n = n % 12;
	x = m / 60;
	if ((double)abs((30 * (n + m / 60 - m / 5))) <= 180) {
		cout << (double)abs((30 * (n + m / 60 - m / 5))) << endl;

	}
	else {
		cout << 360-(double)abs((30 * (n + m / 60 - m / 5))) << endl;
	}
}