#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	long long int k, x,s,b;
	cin >> k >> x;
	s = x - k + 1;
	b = x + k - 1;
	for (long long int i = s; i <= b; i++) {
		cout << i << " ";
	} 

}