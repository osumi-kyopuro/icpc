#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n, d;
	cin >> n >> d;
	int x[20][20];
	double t = 0, count = 0;
	double y[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cin >> x[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = i + 1; k < n; k++) {
			for (int j = 0; j < d; j++) {
			
	
				if (i == n - 1) {
					t += pow(abs(x[i][j] - x[0][j]), 2);
				}
				else {
					t += pow(abs(x[i][j] - x[k][j]), 2);

				}
			}
			y[i][k] = sqrt(t);
			t = 0;
			int a = y[i][k];
			if (a - y[i][k] == 0) {
				count++;
			}

		}
		
	}
	cout << count << endl;

	
}