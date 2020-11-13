#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<utility>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>k(n,0);
	vector<int>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec.at(i);
		while (vec.at(i) % 2 == 0) {
			vec.at(i) /= 2;
			k.at(i)++;
		}
	}
	sort(k.begin(), k.end());
	cout << k.at(0) << endl;
	

}