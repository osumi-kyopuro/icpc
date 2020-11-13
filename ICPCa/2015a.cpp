#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	while (true) {
		int m, bn, sn,g=0,max=0;
		cin >> m >> sn >> bn;
		if (m == 0 && bn == 0 && sn == 0) {
			break;
		}
		vector<int>vec(m);
		for (int i = 0; i < m; i++) {
			cin >> vec.at(i);
		}
		for (int i = sn-1; i <bn; i++) {
			if ((vec.at(i) - vec.at(i + 1)) >= max && g <= i+1) {
				g=i+1;
				max = vec.at(i) - vec.at(i + 1);
			}
		}
		cout << g << endl;
	}
}