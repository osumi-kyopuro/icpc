#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	string s;
	cin >> s;
	string mae = s.substr(0, 2);
	string usiro = s.substr(2, 2);
	if (mae=="00"||(mae >= "13"&&mae <= "99")&&usiro >="01" && usiro <= "12") {
		cout << "YYMM" << endl;
	}
	
	else if (mae >= "01"&&mae <= "12"&&usiro >= "01" && usiro <= "12") {
		cout << "AMBIGUOUS" << endl;
	}
	else if (mae >= "01"&&mae <= "12"&&usiro >= "00" && usiro <= "99") {
		cout << "MMYY" << endl;
	}
	else {
		cout << "NA" << endl;
	}
	

}