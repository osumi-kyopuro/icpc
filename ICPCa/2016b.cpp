#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	while (true) {
		int n;
		cin >> n;
		int j1 = 0;
		int j2 = 0;
		int k1 = 0;
		int k2 = 0;
		int j = 0;
		int x = 0;
		int flag = 0;
		if (n == 0) {
			break;
		}
		vector<char>vec(n);
		vector<int>count(26, 0);
		for (int i = 0; i < n; i++) {
			cin >> vec.at(i);
			//cout <<(int)vec.at(i) << endl;

			j = (int)(vec.at(i) - 'A');
			//cout <<"a"<< x << endl;
			count.at(j)++;
			if (count.at(j) > j1) {
				if (j != k1) {
					j2 = j1;
					k2 = k1;
					j1 = count.at(j);
					k1 = j;

				}
				else {
					j1 = count.at(j);
					k1 = j;
				}
			}
			else if (count.at(j) > j2) {
				j2 = count.at(j);
				k2 = j;
			}
			/*cout << j1 << endl;
			cout << k1 << endl;
			cout << j2 << endl;
			cout << k2 << endl;*/
			if (j1 > j2 + n - 1 - i && flag == 0) {
				cout << (char)(k1 + 'A') << " " << i + 1 << endl;
				flag++;
				//break;//n‚É•¶Žš‚ª“ü—Í‚³‚ê‚ÄƒGƒ‰[‚ð‚Í‚­
			}
			else if (i == n - 1 && flag == 0) {
				cout << "TIE" << endl;
			}
		}
	}
}