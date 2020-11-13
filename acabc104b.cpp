#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	string  n;
	cin >> n;
	int count = 0,soeji;
	if (n[0] == 'A') {
		
		for (int i = 2; i < n.size()-1; i++) {
			if (n[i] == 'C') {
				soeji = i;
				count++;
				
			}
		}
		for (int i = 1; i < n.size(); i++) {
			if (i != soeji && (n[i]<'a'||n[i]>'z')) {
				cout << "WA" << endl;
				exit(0);
			}
		}
	}
	if (count == 1) {
		cout << "AC" << endl;
	}
	else {
		cout << "WA" << endl;
	}

}
