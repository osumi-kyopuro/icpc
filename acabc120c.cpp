#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	int count0 = 0;
	int count1 = 0;
	for (int j = 0; j < s.size();j++) {
		if (s[j]=='0') {
			count0++;
			
		}
		else {
			count1++;
		}
		
	}
	cout << 2*min(count0,count1) << endl;
}