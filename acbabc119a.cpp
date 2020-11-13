#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	string s;
	cin >> s;
	string y = s.substr(0, 4);
	string m = s.substr(5, 2);
	string d = s.substr(8, 2);
	if (y <= "2019"&&m <= "04"&&d <= "30") {
		cout << "Heisei" << endl;
	}
	else {
		cout << "TBD" << endl;
	}
}
