#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int n,sum=0;
	cin >> n;
	vector<int>v(n);
	vector<int>c(n);
	vector<int>s(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		s[i] = v[i] - c[i];
		//cout << s[i] << endl;
	}
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		if (s[i] >= 0) {
			sum += s[i];
		}
		else {
			break;
		}
	}
	cout << sum << endl;
	
}