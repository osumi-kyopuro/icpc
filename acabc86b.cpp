#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<map>
#define ll long long
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int s = stoi(a+b);
	for (ll i = 1; i <= 1000; i++) {
		if (i*i == s) {
			cout << "Yes" << endl;
			exit(0);
		}
	}

	cout << "No" << endl;
}