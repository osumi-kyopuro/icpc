#include<iostream>2
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
	ll a, b, c;
	cin >> a >> b >> c;
	cout << a% (1000000000 + 7)*b % (1000000000 + 7)*c % (1000000000 + 7) << endl;
}