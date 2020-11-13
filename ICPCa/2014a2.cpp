#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int keisan(int x, int y, int z);
int main() {
	while (true) {
		int x, y, s;
		int answer=0;
		cin >> x >> y >> s;
		if (x == 0 && y == 0 && s == 0) {
			break;
		}
		for (int i = 1; i < s; i++) {
			for (int j = 1; j < s; j++) {
				if (keisan(i,j,x)==s) {
					answer=max(answer,keisan(i,j,y));

				}
			}
		}

		cout << answer << endl;
		
	}
}

int keisan(int i, int j, int x) {
	return i * (100 + x) / 100 + j*(100+x)/100;
}