#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int a, b,sum=0,count=0;
	cin >> a >> b;
	if (b==1) {
		cout << "0" << endl;
		exit(0);
	}

	sum += a;
	count++;
	while (b > sum) {
		sum += a-1;
		count++;
	}
	cout << count << endl;
}