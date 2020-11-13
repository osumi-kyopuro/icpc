#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int main() {
	string s;
	int s2,m,sa=1000;
	cin >> s;
	string s1;
	for (int i = 0; i < s.size() - 2; i++) {
		s1 = s.substr(i, 3);
		//cout << s1 << endl;
		m = stoi(s1);
		//cout << m << endl;
		s2 = abs(m - 753);
		
		sa = min(sa, s2);
	}
	cout << sa<< endl;
}