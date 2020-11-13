#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	long long n, a, b, c, d, e;
	cin >> n >> a >> b >> c >> d >> e;
	cout <<(long long) ceil((double)n / min({a,b,c,d,e})) + 4 << endl;
}