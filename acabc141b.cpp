#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	string s;
	cin >> s;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if ((i + 1) % 2 == 0) {
			if (s[i] == 'L') {
				count++;
			}
			else if (s[i] == 'U') {
				count++;
			}
			else if (s[i] == 'D') {
				count++;
			}
			else {
				cout << "No" << endl; 
				exit(0);

			}
		}
		else if((i+1)%2==1){

			if (s[i] == 'R') {
				count++;
			}
			else if (s[i] == 'U') {
				count++;
			}
			else if (s[i] == 'D') {
				count++;
			}
			else {
				cout << "No" << endl;
				exit(0);
			}

		}
	}
	if (count = s.size()) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}