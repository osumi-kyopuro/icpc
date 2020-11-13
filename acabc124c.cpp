#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string s;
	char t;
	int count=0;
	cin >> s;
	for (int i = 0; i < s.size()-1; i++) {
		if (s[i+1]==s[i]) {
			if (s[i] == '0') {
				s[i + 1] = '1';
				count++;
			}
			else if(s[i]=='1'){
				s[i + 1] = '0';
				count++;
			}
		}
	}
	cout << count << endl;
}