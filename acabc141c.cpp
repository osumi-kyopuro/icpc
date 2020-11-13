#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n, k, q;
	cin >> n >> k >> q;
	vector<int>a(q);
	vector<int>h(n,k);
	vector<int>z(n,0);
	for (int i = 0; i < q; i++) {
		cin >> a[i];
		h[a[i]-1]++;
	}
	for (int j = 0; j < n; j++) {
		h[j] -= q;
	}
	for (int j = 0; j < n; j++) {
		if (h[j]>0) {
			cout << "Yes" << endl;
		}
		
		else {
			cout << "No" << endl;
		}
	

		
	}


	
}