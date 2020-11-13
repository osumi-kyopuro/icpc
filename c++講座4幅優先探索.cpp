#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;

int  main()  {
	int r, c;
	int sy, sx;
	vector<vector<char>>ban(r, vector<char>(c));
	cin >> r >> c;
	cin >> sy >> sx;
	string a;
	getline(cin, a);
	for (int i = 0; i < r; i++) {
		getline(cin, a);
		for (int j = 0; j < c; j++) {
			ban.at(i).at(j)=a.at(j);
		
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ban.at(i).at(j) = 0;
			if (ban.at(i + 1).at(j)=='.'||ban.at(i).at(j+1)=='.') {

			}

		}
	}




	

	
}