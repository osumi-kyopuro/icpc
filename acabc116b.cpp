#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int s,flag=0;
	int i = 0;
	cin >> s;
	int a[100000] = {0};
	a[0] = s;
	//cout << a[0] << endl;
	a[1] = (a[0]) / 2;
	//cout << a[1] << endl;
	i++;
	while (true) {
		
		//cout << i << endl;
		if (i == 0) {
			i += 2;
		}
		if ((a[i-1])% 2 == 0) {
			a[i] = (a[i-1]) / 2;
			//cout << a[i - 1] << endl;
			//cout << a[i] << endl;
		}
		else {
			a[i] = 3 * (a[i-1]) + 1;
			//cout << a[i-1] << endl;
			//cout << a[i] << endl;
		}
		for (int j = 0; j<i ; j++) {
			if (a[j] == a[i]) {
				//cout << i << endl;
				flag++;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
		i++;
	}
	cout <<i+1 << endl;
}
