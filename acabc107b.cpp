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
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
	vector<string>a2(h);
	vector<bool>kesiG(h,false);
	vector<bool>kesiR(w, false);
	for (int i = 0; i < h; i++) {
		if (a[i][0] == '.') {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == '#') {
					a2[i] = a[i];
					break;
				}
				else if (j == w - 1) {
					//cout << "aaa" << endl;
					kesiG[i] =true;
				}
			}
		}
		else if (a[i][0] == '#') {
			a2[i] = a[i];
		}
		
		
	}


	
	for (int i = 0; i < w; i++) {
		if (a[0][i] == '.') {
			for (int j = 0; j < h; j++) {
				if (a[j][i] == '#') {
					a2[i] = a[i];
					break;
				}
				else if (j == h - 1) {
					//cout << "aaa" << endl;
					kesiR[i] = true;
				}
			}
		}
		else if (a[0][i] == '#') {
			a2[i] = a[i];
		}


	}
	
	for (int i = 0; i < h; i++) {
		flag = false;
		for (int j = 0; j < w; j++) {
			//flag = false;
			if (kesiG[i] != true && kesiR[j] != true) {
				cout << a2[i][j];
				flag = true;
			}
			
		}
		if (flag == true) {
			cout << endl;
		}
	}


}