#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	long long n, q;
	cin >> n >> q; 
	string s;
	cin >> s;
	vector<long long>t(n);
	long long l, r,count=0;
	for (long long i = 1; i < n; i++) {
		if (s[i - 1] == 'A'&&s[i] == 'C') {
			count++;
		}
		t[i] = count;
	}
	for (long long i = 0; i < q; i++) {
		cin >> l >> r;
		l--;
		r--;
		cout << t[r] - t[l] << endl;
	}
}