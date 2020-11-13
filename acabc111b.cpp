#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int n,i;
	cin >> n;
	i = n;

	for (;;) {
		
		if (i == 111 || i == 222 || i == 333 || i == 444 || i == 555 || i == 666 || i == 777 || i == 888 || i == 999) {
			cout << i << endl;
			break;
		}
		i++;
	}

}
