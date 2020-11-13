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
			for (int i = 0; i < a.size(); i++) {
				//cout << "BYE1" << endl;
				for (int j = i; j < b.size(); j++) {
					//cout << "BYE2" << endl;
					if (a.at(i) == '"'||b.at(i)=='"') {
						cout << "BYE3" << endl;
						for (int k = 1;i+k<a.size(); k++) {
							//cout << "BYE4" << endl;
							if (a.at(i+k) != b.at(j + k)) {
								cout << "BYE" << endl;
								x++;
								break;
							}
							else if (a.at(i + k+1) == '"'&&b.at(j+k+1)=='"') {
								cout << "BYExx" << endl;
								//x++;
								break;
							}
						}
					}
				}
			}
			if (x !=0) {
				cout << "CLOSE" << endl;
			}
			else {
				cout << "DIFFERENT" << endl;
			}
		
		}

	}
}