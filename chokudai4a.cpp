#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
int i, j;
int l[30][30];
int r[30][30];
int Dice(int l[30][30],int r[30][30],int i,int j) {
	int sa, s, t;
	s = r[i][j];
	t = l[i][j];
	sa = s+t;
	return rand() %9+1 ;
}
int main() {
	int n;
	vector<int>b(3);
	cin >> n >> b[0] >> b[1] >> b[2];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> l[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> r[i][j];
		}
	}
	//srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			cout << Dice(l, r, i, j)<<" ";
			
		}
		cout << endl;
	}
	
}