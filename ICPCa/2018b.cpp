#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	while (true) {
		int n, m, t, p,o=1;
		cin>> n >> m >> t >> p;
		if (n == 0 && m == 0 && t == 0 && p == 0) {
			break;
		}
		vector<int>d(t);
		vector<int>c(t);
		for (int i = 0; i < t; i++) {
			cin >> d.at(i);
			cin >> c.at(i);
		}
		vector<vector<int>>count(n, vector<int>(m,1));
		for (int i = 0; i < n;i++) {
			for(int j=0;j<m;j++){
				if (d.at(i)==1) {
					n -= c.at(i);
					if (i<=c.at(i)) {
						count.at(i).at(j)+=o;
						o *= 2;
						cout << o << endl;
					}
				}
				else {
					m -= c.at(i);
					if (j <=c.at(i)) {
						count.at(i).at(j)+=o;
						o *= 2;
					}
				}
			}	
		}
		vector<int>x(p);
		vector<int>y(p);
		for (int i = 0; i < p; i++) {
			cin >> x.at(i) >> y.at(i);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (x.at(i) + 0.5 == i&&y.at(i)+0.5==j) {
					cout << count.at(i).at(j) << endl;
				}
			}
		}
		
	}
	system("pause");

}