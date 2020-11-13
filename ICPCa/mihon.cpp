#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<int>vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec.at(i);
		}
		for (int i = 0; i < n; i++) {
			cout <<vec.at(i)<<endl;
		}
		
	}
}