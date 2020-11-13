#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
constexpr int func(int n) {
	return n * n;
}
int  main() { 
	constexpr int p = func(5);
	//cout << p << endl;
}