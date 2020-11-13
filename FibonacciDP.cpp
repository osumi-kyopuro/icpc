#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int dp[50];
int fib(int n) {
	if (n == 0 || n == 1) {
		return dp[n] = 1;
	}
	if (dp[n] != -1) {
		return dp[n];
	}
	return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() {
	int n;
	for (int i = 0; i < 50; i++) {
		dp[i] = -1;
	}
	cin >> n;
	cout << fib(n) << endl;
}
