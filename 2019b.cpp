#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main() {
	while (true) {
		int h, w;
		cin >> h >> w;
		if (h == 0 && w == 0) {
			break;
		}

		string r;
		vector<vector<char>>vec(h,vector<char>( w));
		getline(cin, r);
		for (int i = 0; i < h; i++) {
			getline(cin, r);
			for (int j = 0; j < w; j++) {
				vec.at(i).at(j) = r.at(j);

			}
		}
		string s;
		cin >> s;
		int kazu=0;
		int maei=0;
		int maej=0;
		int flag = 0;
		for (int k = 0; k < s.size(); k++) {
			//cout << s.at(k) << endl;
			flag = 0;
			while (flag==0) {
				for (int i = 0; i < h; i++) {
					for (int j = 0; j < w; j++) {
						if (s.at(k) == vec.at(i).at(j)) {
							kazu += abs(i- maei)+abs (j - maej)+1;
							//cout << kazu << endl;
							//cout << "basyoi" << i << endl;
							//cout << "basyoj" << j << endl;
							maei = i;
							maej = j;
							flag++;
							break;

						}

					}
					if (flag == 1) {
						break;
					}
				}
			}
		}
		cout << kazu << endl;
	}
}