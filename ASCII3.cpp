#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	//bool arr[1000000] = { true };
	
	vector<bool>arr(1000001,true);
	
	for (int i = 2; i < sqrt(1000001); i++) {
		if (arr[i]) {
			for (int j = 2*i; j <= 1000000; j+=i) {
				arr[j] = false;
			}
		}
	}
	cout<<"No"<<endl;
	for (int i = 2; i < 1000001; i++) {
		if (arr[i]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
//	cout << "hello world" << endl;
}