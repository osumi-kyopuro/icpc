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
		int k = 0;
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
			//cout << as << endl;
			//cout << bs << endl;

			string amae = a.substr(0, aPos);
			string bmae = b.substr(0, bPos);
			//cout << amae << endl;
			//cout << bmae << endl;

			string ausiro = a.substr(laPos+1, a.size()-aPos - 1);
			string busiro = b.substr(lbPos+1, b.size()-bPos - 1);
			//cout << ausiro << endl;
			//cout << busiro << endl;

			int a2Pos = as.find_first_of('"');
			int b2Pos = bs.find_first_of('"');
			int la2Pos = as.find_last_of('"');
			int lb2Pos = bs.find_last_of('"');
			//cout << a2Pos << endl;
			//cout << b2Pos << endl;
			//cout << la2Pos << endl;
			//cout << lb2Pos << endl;
			if (a2Pos < 0 && b2Pos < 0) {
				if (as != bs&&amae==bmae&&ausiro==busiro) {
					cout << "CLOSE" << endl;
				}
				else {
					cout << "DIFFERENT" << endl;
				}
			}
			else {
				while (true) {

					string amojiretuteisuu = as.substr(0, a2Pos);
					string bmojiretuteisuu = bs.substr(0, b2Pos);


					//cout << amojiretuteisuu << endl;
					//cout << bmojiretuteisuu << endl;

					string lamojiretuteisuu = as.substr(la2Pos + 1, as.size() - la2Pos - 1);
					string lbmojiretuteisuu = bs.substr(lb2Pos + 1, bs.size() - lb2Pos - 1);

					//cout << lamojiretuteisuu << endl;
					//cout << lbmojiretuteisuu << endl;

					as = as.substr(a2Pos + 1, la2Pos - a2Pos - 1);
					bs = bs.substr(b2Pos + 1, lb2Pos - b2Pos - 1);
					a2Pos = as.find_first_of('"');
					b2Pos = bs.find_first_of('"');
					la2Pos = as.find_last_of('"');
					lb2Pos = bs.find_last_of('"');
					//cout << a2Pos << endl;
					//cout << b2Pos << endl;
					//cout << la2Pos << endl;
					//cout << lb2Pos << endl;
					//if (a2Pos < 0 || b2Pos < 0) {
					if (amojiretuteisuu == bmojiretuteisuu && lamojiretuteisuu == lbmojiretuteisuu) {
						if (a2Pos < 0 || b2Pos < 0) {
							cout << "DIFFERENT" << endl;
							break;
						}
					}
					else if (amojiretuteisuu == bmojiretuteisuu && lamojiretuteisuu != lbmojiretuteisuu) {
						k++;
					
						if (a2Pos < 0 || b2Pos < 0&&k==1) {
							cout << "CLOSE" << endl;
							break;
						}
					}
					else if (amojiretuteisuu != bmojiretuteisuu && lamojiretuteisuu == lbmojiretuteisuu) {
						k++;
			
						if (a2Pos < 0 || b2Pos < 0&&k==1) {
							cout << "CLOSE" << endl;
							break;

						}
					}
					else {

						if (a2Pos < 0 || b2Pos < 0) {
							cout << "DIFFERENT" << endl;
							break;
						}
					}
				}



			}
		}

	}
}