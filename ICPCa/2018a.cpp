#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstdlib>
using namespace std;

int main() {
while (true) {
	int n, sum = 0, count = 0;
	float ave;
	cin >> n;
	if (n == 0) {
		break;
	}
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
		sum += a.at(i);
	}
	ave = sum / n;
	//cout << ave << endl;
	for (int i = 0; i < n; i++) {
		if (a.at(i) <= ave) {
			count++;
			//cout << "i=" << i << endl;
		}
	}
	cout << count << endl;



}
system("pause");
}