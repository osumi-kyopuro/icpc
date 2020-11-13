#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int n,big,flag=0,sum=0;
	cin >> n;
	vector<int>l(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	big = l[0];
	for (int i = 0; i < n; i++) {
		big = max(big, l[i]);

	}
	for (int i = 0; i < n; i++) {
		if (big == l[i] && flag == 0) {
			flag++;
			continue;
		}
		else {
			sum += l[i];
		}
	}
	if (sum > big) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}


}