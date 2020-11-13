#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	long long	a = 0;
	cin >> n;
	int p[1000000000];
	for (int i = 0; i < n - 1; i++) {
		
		//p[i] = i + 2;
		a += i + 1;
	}
	cout << a << endl;
}
