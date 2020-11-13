#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int n, q,time;
	string name;
	queue<pair<string, int>>Q;
	cin >> n >> q;
	
	for (int i = 0; i < n; i++) {
		cin >> name >> time;
		Q.push(make_pair(name, time));
	}
	pair<string, int>p;
	int a,ktime=0;
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		a = min(p.second, q);
		ktime += a;
		if (a < p.second) {
			p.second -= a;
			Q.push(p);
		}
		else {
			cout << p.first << " " << ktime << endl;
		}
	}
}