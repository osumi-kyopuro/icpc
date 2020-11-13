#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	//vector<int>a(100000);
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
		//cout << a[i] << endl;
	int q, k, sum = 0;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin>>k;
		if (*lower_bound(a.begin(),a.end(), k) == k) {
			sum++;
		}
	}
	
	cout << sum << endl;
}