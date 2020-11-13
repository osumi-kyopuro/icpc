#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int h, w;
	bool flag = false;
	cin >> h >> w;
	vector<string>a(h);
	vector<bool>kesiG(h,false);
	vector<bool>kesiR(w,false);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
	for (int i = 0; i<h; i++) {
		if (a[i][0] == '.') {


			for (int j = 0; j < w; j++) {
				if (a[i][j] == '.'&&j==w-1) {
					kesiG[i]=true;
				}
				else if (a[i][j]=='#') {
					break;
				}
			}
		}
	}
	for (int i = 0; i<w; i++) {
		if (a[0][i] == '.') {

			//cout << i << endl;
			for (int j = 0; j < h; j++) {
				if (a[j][i] == '.'&&j == h - 1) {
					kesiR[i] = true;
					//cout << "bb" << endl;
				}
				else if (a[j][i] == '#') {
				//	cout << j << endl;
					break;
				}
			}
		}
	}
	
	for (int i = 0; i < h; i++) {
		
		bool flag = false;
		for (int j =0 ; j < w; j++) {
			if (kesiR[j] != true && kesiG[i] != true) {
				cout << a[i][j];
				flag = true;
			}
		}
		if (flag == true) {
			cout << endl;
		}
	}
	
}