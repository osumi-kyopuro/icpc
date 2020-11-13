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
	string a, b, c;
	char ima;
	cin >> a >> b >> c;
	bool flag = true;
	while (true) {
		if (flag==true||ima == 'a') {
			flag = false;
			if (a.size() == 0) {
				cout << 'A' << endl;
				exit(0);
			}
			ima = *(a.begin());
			a.erase(a.begin());
		}
		else if (ima == 'b') {
			if (b.size() == 0) {
				cout << 'B' << endl;
				exit(0);
			}
			ima = *(b.begin());
			b.erase(b.begin());
		}
		else {
			if (c.size() == 0) {
				cout << 'C' << endl;
				exit(0);
			}
			ima = *(c.begin());
			c.erase(c.begin());
		}
	}
}
