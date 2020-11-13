#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n,count=0;
	cin >> n;
	vector<int>wari(n+1,0);
	for (int i = 1; i <= n; i += 2) {
		for (int j = 1; j <= n; j++) {
			if (i%j == 0) {
				wari[i]++;
			}
		}
	}
	for (int i = 1; i <= n; i+=2) {
		if (wari[i] == 8) {
			count++;
		}
	}
	cout << count << endl;
	
	
}