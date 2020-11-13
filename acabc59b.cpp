#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<climits>
#include<map>
#define ll long long
using namespace std;

int main() {
	string a, b; 
	cin >> a >> b;
	if (a.size() > b.size()) {
		cout << "GREATER" << endl;
	}
	else if (a.size() < b.size()) {
		cout << "LESS" << endl;
	}
	else {
		for (ll i = 0; i < a.size();i++) {
			if (a[i] > b[i]) {
				cout << "GREATER" << endl;
				exit(0);
			}
			else if (a[i] < b[i]) {
				cout << "LESS" << endl;
				exit(0);
			}

		}
		cout << "EQUAL" << endl;
	}

}



