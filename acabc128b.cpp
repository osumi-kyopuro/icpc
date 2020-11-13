#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<string>s(n);
	vector<int>p(n);
	vector<int>t(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> p[i];
		t[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (s[j] > s[j+1]) {
				swap(t[j], t[j+1]);
				swap(s[j], s[j+1]);
				swap(p[j], p[j + 1]);
			}
			if (s[j] == s[j+1] && p[j] < p[j+1]) {
				swap(t[j], t[j+1]);
				swap(s[j], s[j + 1]);
				swap(p[j], p[j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << t[i]+1 << endl;
		//cout << p[i] << endl;
	}

}