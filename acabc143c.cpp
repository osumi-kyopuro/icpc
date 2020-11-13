#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	string s;
	int n;
	cin >> n;
	cin >> s;
	int count = 1;
	for (int i = 0; i < s.size()-1; i++) {
		if (s[i] != s[i + 1]) {
			count++;
		}
	}
	cout << count << endl;
}