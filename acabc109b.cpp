#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n,count=0,q=0;
	cin >> n;
	vector<string>w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i < n; i++) {
		if (w[i - 1][w[i - 1].size() - 1] == w[i][0]) {
			count = 0;
			for (int j = 0; j < i; j++) {
				if (w[i] != w[j]) {
					count++;
					//cout << count << endl;
					if(count == i) {
						q++;
						//cout << q << endl;
					}

				}
			}

		}
		else {
			break;
		}
	}
	if (q == n-1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}