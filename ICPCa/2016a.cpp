#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		int sa;
		vector<int>vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec.at(i);
		}
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		sa = vec.at(0) - vec.at(1);
		for (int i = 0; i < n-1; i++) {
			if (vec.at(i) - vec.at(i + 1)<sa) {
				sa = vec.at(i) - vec.at(i + 1);
			}
		}
		cout << sa << endl;
	}
}