#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int m, d,t,t2,count=0;
	cin >> m >> d;
	for (int i = 1; i <= m; i++) {
		for (int j = 22; j <= d; j++) {
			t = j % 10;
			t2 = j /10;
			if (t*t2 == i&&t>=2&&t2>=2) {
				//cout << m <<" "<<t2<<" "<<t << endl;
				count++;
			}
		}
	}
	cout << count << endl;
}