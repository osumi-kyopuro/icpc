#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int X, Y, n, m,bx=-100,by=100;
	cin >> n >> m >> X >> Y;
	vector<int>x(n);
	vector<int>y(m);

	for (int i = 0; i < n; i++) {
		cin >> x[i];
		bx = max(x[i], bx); 
	}
	for (int j = 0; j < m; j++) {
		cin >> y[j];
		by = min(y[j], by);
		
	}
	//cout << bx << endl;
	//cout << by << endl;
	for (int z = X+1; z <= Y; z++) {
		if (z > bx&&z <= by) {
			cout << "No War" << endl;
			exit(0);
		}
	}
	cout << "War" << endl;


	
}