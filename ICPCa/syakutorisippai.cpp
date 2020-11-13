#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main() {
	while(true) {
		int b;
		cin >> b;
		if (b == 0) {
			break;
		}
		//int sum = 0;
		//int ue = 0;
		for (int sita= 1; sita<b+1; sita++) {
			int sum = 0;
			int ue = sita;
			while (ue<b+1&&sum+ue<b+1) {
				sum += ue;
				ue++;
			}
			/*if (sita == ue) {
				ue++;
			}
			else {
				sum -= sita;
			}*/
			if (sum == b) {
				cout <<sita<< " "<<ue - sita << endl;
				break;
			}

		}
		
	}
	//system("pause");
}