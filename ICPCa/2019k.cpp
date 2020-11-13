#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<typeinfo>

using namespace std;
int main() {
	int n;
	cin >> n;
	string str;
	getline(cin, str);
	int count = 0;
	for (int i = 0; i < n; i++) {
		//string str;
		getline(cin, str);
		cout << str.size() << endl;//hello
	}
}