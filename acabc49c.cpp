#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string s;
	cin >> s; 
	reverse(s.begin(), s.end());
	//vector<string>t={ "dream","dreamer","erase","eraser" };
	for (long long i = 0; i < s.size();) {
		if (s.substr(i, 7) == "remaerd") {
			i += 7;
			//cout<< i << endl;
		}
		else if (s.substr(i, 6) == "resare") {
			i += 6;
			//cout << i << endl;
		}
		else if (s.substr(i, 5) == "maerd" || s.substr(i, 5) == "esare") {
			i += 5;
			//cout << i << endl;
		}
		else {
			cout << "NO" << endl;
			exit(0);
		}
		
	
	}
	cout << "YES" << endl;
	
}