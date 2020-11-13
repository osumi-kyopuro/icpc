#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<queue>
#include<utility>
using namespace std;
int main() {
	long long int n, k = 0,s=1;
	cin >> n;
	vector<long>vec(n);

	for (long int i = 0; i < n; i++) {
		cin >> vec.at(i);
		//cout << vec.at(i) << endl;
	}

	for (long int i = 0; i < n; i++) {
		if (vec.at(i) > s) {
			vec.at(i)--;
			s = vec.at(i);
			//cout << vec.at(i) << endl;
		}
		if (vec.at(i) < s) {
			cout << "No" << endl;
			exit(0);
		}
	}
	cout << "Yes" << endl;

}

	
