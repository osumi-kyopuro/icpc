#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[50];
int solve(int i,int  M) {
	if (M == 0) {
		return 1;
	}
	else if (i >= n) {
		return 0;
	}
	int res = solve(i+1, M) || solve(i+1, M - a[i]);
	return res;
}


int main() {
	int q;
	cin>>n;
	for (int i = 0; i < n; i++) {
	cin>>a[i];
	}
	cin>>q;
	int m;
	for (int i = 0; i < q; i++) {
		cin>>m;
		if(solve(0,m)){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}

}