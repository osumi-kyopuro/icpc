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
			//while (aPos > 0 && bPos > 0 && laPos > 0 && lbPos > 0) {
			string as = a.substr(aPos + 1, laPos - aPos - 1);
			string bs = b.substr(bPos + 1, lbPos - bPos - 1);
			cout << as << endl;
			cout << bs << endl;
			
			int a2Pos = as.find_first_of('"');
			int b2Pos = bs.find_first_of('"');
			int la2Pos = as.find_last_of('"');
			int lb2Pos = bs.find_last_of('"');
			//cout << a2Pos << endl;
			//cout << b2Pos << endl;
			if (a2Pos < 0 || b2Pos < 0) {
				if (as != bs) {
					cout << "CLOSE" << endl;
				}
				else {
					cout << "DIFFERENT" << endl;
				}
			}
			else{

				string amojiretuteisuu = as.substr(0, a2Pos);
				string bmojiretuteisuu = bs.substr(0, b2Pos);

				cout << amojiretuteisuu << endl;
				cout << bmojiretuteisuu << endl;

				string lamojiretuteisuu = as.substr(la2Pos + 1, as.size() - la2Pos - 1);
				string lbmojiretuteisuu = bs.substr(lb2Pos + 1, bs.size() - lb2Pos - 1);

				cout << lamojiretuteisuu << endl;
				cout << lbmojiretuteisuu << endl;




				if (amojiretuteisuu == bmojiretuteisuu && lamojiretuteisuu == lbmojiretuteisuu) {
					cout << "DIFFERENT" << endl;
				}
				else if (amojiretuteisuu == bmojiretuteisuu && lamojiretuteisuu != lbmojiretuteisuu) {
					cout << "CLOSE" << endl;
				}
				else if (amojiretuteisuu != bmojiretuteisuu && lamojiretuteisuu == lbmojiretuteisuu) {
					cout << "CLOSE" << endl;
				}
				else {
					cout << "DIFFERENT" << endl;
				}
			}

		}

	}
}