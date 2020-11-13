#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main() {
	while (true) {
		int b;
		cin >> b;
		if (b == 0) {
			break;
		}
		int sita = 1;
		int ue = 1;
		int sum = 1;
		while (true) {
			if (b > sum) {
				ue++;
				sum += ue;
			}
			else if (b < sum) {
				sum -= sita;
				sita++;
			}
			else {
				break;
			}
		}
		cout << sita << " " << ue - sita + 1 << endl;



	}
}
