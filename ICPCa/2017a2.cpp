#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	while (true) {
		int n, m,sum=0;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		vector<int>vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec.at(i);

		}
		for (int i = 0; i < n;i++) {
			for (int j =i+1; j < n;j++) {
				if (m >= vec.at(i) + vec.at(j)&&sum<vec.at(i)+vec.at(j)) {
					sum = vec.at(i) + vec.at(j);
				}
			}
		}

		if (sum == 0) {
			cout << "NONE" << endl;
		}
		else {
			cout << sum << endl;
		}

	}
}