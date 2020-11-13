#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main() {
	int n = 0;

	float s=0,x;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		//cout << (float)1 / a[i] << endl;
		s +=(float) 1 / a[i];
		//cout <<s<< endl;
	}
	x =(float) 1 / s;
	//cout << x << endl;
	printf("%.5f", x);

}