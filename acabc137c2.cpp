#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	long long int n,j, count = 0;
	cin >> n;
	//string s;
	vector<string>s(n);
	for (long long int i = 0; i < n; i++) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
	}
	sort(s.begin(), s.end());
	/*for (string x : s) {
		cout << x << endl;
	}*/
	for (long long int i = 0; i < n; ) {
		for(j = i + 1; j < n;j++) {

			if (s[i] != s[j]) {
				break;
			 }
		}
		count += (j - i)*(j - i - 1) / (2*1);
		i = j;
	}

	cout << count << endl;
}