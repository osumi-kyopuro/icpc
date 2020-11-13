#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	while (true) {
		int n, m;
		int s=0;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		vector<vector<int>>vec(m,vector<int>(n));
		vector<int>sum(n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> vec.at(i).at(j);
				sum.at(j) += vec.at(i).at(j);
				//cout << i<<" "<<sum.at(j) << endl;

			}
		}
		for (int i = 0; i < n; i++) {
			s = max(s, sum.at(i));
		}
		cout << s << endl;

	}
}