#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<utility>
#include<queue>
using namespace std;
int main() {
	int n, m, x;
	cin >> n >> m >> x;
	int k = 0;
	int k2 = 0;
	vector<int>a(m);
	for (int i = 0; i < m; i++) {
		cin >> a.at(i);

		for (int j = x; j < n + 1; j++) {
			if (j == a.at(i)) {
				k++;
				//cout << "k" << endl;
			}
		}
		for (int k = x; k >= 0; k--) {
			if (k == a.at(i)) {
				k2++;
				//cout << "k2" << endl;
			}

		}
	}
	cout << min(k, k2) << endl;

}