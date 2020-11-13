#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	while (true) {
		string a;
		string b;
		int x = 0;
		cin >> a >> b;
		if (a.at(0) == '.') {
			break;
		}
		if (a == b) {
			cout << "IDENTICAL" << endl;
		}
		else {
			int aPos = a.find_first_of('"');
			int bPos = b.find_first_of('"');
			int laPos = a.find_last_of('"');
			int lbPos = b.find_last_of('"');
			/*cout << aPos << endl;
			cout << bPos << endl;
			cout << laPos << endl;
			cout << lbPos << endl;*/
			string as = a.substr(aPos+1,laPos-aPos-1);
			string bs = b.substr(bPos + 1, lbPos - bPos - 1);
			cout << as << endl;
			cout << bs << endl;
			int a2Pos = as.find_first_of('"');
			int b2Pos = bs.find_first_of('"');
			int la2Pos = as.find_last_of('"');
			int lb2Pos = bs.find_last_of('"');

			string amojiretuteisuu = as.substr(0,a2Pos);
			string bmojiretuteisuu = bs.substr(0, b2Pos);
			cout << amojiretuteisuu << endl;
			cout << bmojiretuteisuu << endl;


			
			if (amojiretuteisuu == bmojiretuteisuu) {
				cout << "CLOSE" << endl;
			}

		}

	}
}