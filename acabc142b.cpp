#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int main() {

	int n,k,count=0;
	cin >>n>> k;
	vector<int>h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		if (h[i] >= k) {
			count++;
		}
	}
	cout << count << endl;


}