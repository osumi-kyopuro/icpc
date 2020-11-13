#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int main() {
	double n,count=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			count++;
		}
	}
	printf("%.9f",count/n);

}