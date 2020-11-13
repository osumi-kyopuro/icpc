#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int a, b, k,count=0;
	cin >> a >> b >> k;
	vector<int>sum(b,0);
	for (int i = 1; i <=min(a,b) ; i++) {
		if (a%i == 0 && b%i == 0) {
			sum[count] += i;
			count++;
		}
	}
	cout << sum[count - k] << endl;
}
