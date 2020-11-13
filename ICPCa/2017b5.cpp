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
		int n = 0;
		int flag = 0;
		int flag2 = 0;
		cin >> a >> b;
		if (a.at(0) == '.') {
			break;
		}
		if (a == b) {
			cout << "IDENTICAL" << endl;
		}
		else {
			int apos = a.find_first_of('"');
			int bpos = b.find_first_of('"');
			int lapos = a.find_last_of('"');
			int lbpos = b.find_last_of('"');
			//cout << apos << endl;
			//cout << bpos << endl;
			//cout << lapos << endl;
			//cout << lbpos << endl;

			string as = a.substr(apos + 1, lapos - apos - 1);
			string bs = b.substr(bpos + 1, lbpos - bpos - 1);
			//cout << as << endl;
			//cout << bs << endl;

			string amae = a.substr(0, apos);
			string bmae = b.substr(0, bpos);
			//cout << amae << endl;
			//cout << bmae << endl;

			string ausiro = a.substr(lapos + 1, a.size() - apos - 1);
			string busiro = b.substr(lbpos + 1, b.size() - bpos - 1);
			//cout << ausiro << endl;
			//cout << busiro << endl;
			if (amae != bmae || ausiro != busiro) {
				flag2++;
			}

			int a2pos = as.find_first_of('"');
			int b2pos = bs.find_first_of('"');
			int la2pos = as.find_last_of('"');
			int lb2pos = bs.find_last_of('"');
			//cout << a2pos << endl;
			//cout << b2pos << endl;
			//cout << la2pos << endl;
			//cout << lb2pos << endl;
			if (flag == 0) {
				n++;
			}
			if (a2pos < 0 && b2pos < 0 && la2pos < 0 && lb2pos < 0) {
				if (as != bs && amae == bmae && ausiro == busiro) {
					//cout << "1" << endl;
					cout << "CLOSE" << endl;
				}
				else {
					//cout << "1" << endl;
					cout << "DIFFERENT" << endl;
				}
			}
			else if (a2pos < 0 || b2pos < 0 || la2pos < 0 || lb2pos < 0) {
				cout << "DIFFERENT" << endl;
			}
			else {
				while (true) {

					string amojiretuteisuu = as.substr(0, a2pos);
					string bmojiretuteisuu = bs.substr(0, b2pos);


					//cout << amojiretuteisuu << endl;
					//cout << bmojiretuteisuu << endl;

					string lamojiretuteisuu = as.substr(la2pos + 1, as.size() - la2pos - 1);
					string lbmojiretuteisuu = bs.substr(lb2pos + 1, bs.size() - lb2pos - 1);

					//cout << lamojiretuteisuu << endl;
					//cout << lbmojiretuteisuu << endl;

					as = as.substr(a2pos + 1, la2pos - a2pos - 1);
					bs = bs.substr(b2pos + 1, lb2pos - b2pos - 1);
					//cout << as << endl;
					//cout << bs << endl;
					a2pos = as.find_first_of('"');
					b2pos = bs.find_first_of('"');
					la2pos = as.find_last_of('"');
					lb2pos = bs.find_last_of('"');
					//cout << a2pos << endl;
					//cout << b2pos << endl;
					//cout << la2pos << endl;
					//cout << lb2pos << endl;
					if (flag == 0) {
						n++;
					}
					if (amojiretuteisuu == bmojiretuteisuu && lamojiretuteisuu == lbmojiretuteisuu) {
						if (a2pos < 0 && b2pos < 0 && la2pos < 0 && lb2pos < 0) {
							if (k == 1 && n % 2 == 0&&flag2==0) {
								cout << "CLOSE" << endl;
								//cout << "2" << endl;
								break;
							}
							else if (n % 2 != 0 && flag2 == 0&&as!=bs) {
								cout << "CLOSE" << endl;
								break;
							}
							else {
								//cout << "2" << endl;
								cout << "DIFFERENT" << endl;

								break;
							}
						}
						else if(a2pos < 0 || b2pos < 0 || la2pos < 0 || lb2pos < 0&&flag2==0) {
							cout << "DIFFERENT" << endl;
							break;
						}
					}
					else if (amojiretuteisuu == bmojiretuteisuu && lamojiretuteisuu != lbmojiretuteisuu) {
						k++;
						//cout << k << endl;
						flag++;

						if (a2pos < 0 && b2pos < 0 && la2pos < 0 && lb2pos < 0) {
							if (k == 1 && n % 2 == 0&&flag2==0) {
								//cout << "3" << endl;
								cout << "CLOSE" << endl;
								break;
							}
							else if (k == 1 && n % 2 != 0 && flag2 == 0 && as != bs) {
								cout << "CLOSE" << endl;
								break;
							}
							else {
								//cout << "3" << endl;
								cout << "DIFFERENT" << endl;
								break;
							}

						}
						else if (a2pos < 0 || b2pos < 0 || la2pos < 0 || lb2pos < 0) {
							cout << "DIFFERENT" << endl;
							break;
						}
					}
					else if (amojiretuteisuu != bmojiretuteisuu && lamojiretuteisuu == lbmojiretuteisuu) {
						k++;
						flag++;
						//cout << k << endl;
						if (a2pos < 0 && b2pos < 0 && la2pos < 0 && lb2pos < 0) {
							if (k == 1 && n % 2 == 0&&flag2==0) {
								//cout << "4" << endl;
								cout << "CLOSE" << endl;
								break;
							}
							else if (k == 1 && n % 2 != 0 && flag2 == 0 && as != bs) {
								cout << "CLOSE" << endl;
								break;
							}
							else {
								//cout << "4" << endl;
								cout << "DIFFERENT" << endl;
								break;
							}
						}
						else if (a2pos < 0 || b2pos < 0 || la2pos < 0 || lb2pos < 0) {
							cout << "DIFFERENT" << endl;
							break;
						}
					}
					else {
						k += 2;
						if (a2pos < 0 && b2pos < 0 && la2pos < 0 && lb2pos < 0) {
							//cout << "5" << endl;
							cout << "DIFFERENT" << endl;
							break;

						}
						else if (a2pos < 0 || b2pos < 0 || la2pos < 0 || lb2pos < 0) {
							cout << "DIFFERENT" << endl;
							break;
						}
					}
				}



			}
		}

	}
}

