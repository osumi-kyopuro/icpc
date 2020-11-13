#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int four(int a,int b,int c,int d) {
	vector<int>vec(4);
	vec.at(0) = a;
	vec.at(1) = b;
	vec.at(2) = c;
	vec.at(3) = d;
	sort(vec.begin(), vec.end());
	return vec.at(1);
}
int  main() {
	int a, b, c, d;
	cin >> a >> b>>c>>d;
	int p = four(a,b,c,d);

	cout << p << endl;
}