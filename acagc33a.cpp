#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;
int main() {
	int h, w;
	int dy[4] = { 0,1,0,-1 };
	int dx[4] = { 1,0,-1,0 };
	cin >> h >> w;
	int ny, nx;
	int k = 0;
	vector<string>field;
	vector<vector<int>>kuro(h,vector<int>(w,-1));
	field.resize(h);
	for (int i = 0; i < h; i++) {
		cin >> field.at(i);
		//cout << field.at(i) << endl;
	}
	queue<pair<int, int>>q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (field.at(i).at(j) == '#') {
				kuro.at(i).at(j) = 0;
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		pair<int, int>p = q.front();
		q.pop();
		int flag = 0;
		int count = 0;
		for (int i = 0; i < 4; i++) {
			ny = p.first+dy[i];
			nx = p.second + dx[i];
			if (ny >= 0 && nx >= 0 && ny < h&&nx < w
				&&field.at(ny).at(nx) == '.'&&kuro.at(ny).at(nx) == -1) {
				q.push(make_pair(ny, nx));
				flag++;
				if (flag == 1) {
					count++;
				}
				kuro.at(ny).at(nx) = kuro.at(p.first).at(p.second) + count;
				k = kuro.at(ny).at(nx);
				//cout << kuro.at(ny).at(nx) << endl;
			}
		}
	}
	cout << k << endl;
}