#include<iostream>
#include<vector>
using namespace std;
int main() {
	while (true) {
		int n;
		int tmp;
		int sa = 1000000;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<int>vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec.at(i);


		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (vec.at(j - 1) < vec.at(j)) {
					tmp = vec.at(j - 1);
					vec.at(j - 1) = vec.at(j);
						vec.at(j) = tmp;
				}
			}
		}
		for (int i = 1; i < n; i++) {
			if(vec.at(i-1)-vec.at(i)<sa)
			sa = vec.at(i - 1) - vec.at(i);
		}
		cout << sa << endl;
	}
	system("pause");

}