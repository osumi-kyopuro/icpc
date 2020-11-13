#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	long long int n,k=0,count=0;
	cin >> n;
	string s;
	vector<vector<char>>t(n, vector<char>(10,0));
	for (long long int i = 0; i < n; i++) {
		cin >> s;
		sort(s.begin(), s.end());
		for (int j = 0; j < s.size(); j++) {

			t.at(i).at(j) = s.at(j);
		}
	}
	for (long long int i = 0; i < n; i++) {
		for (long long int j = i+1; j < n; j++) {
		
			if (t.at(i) == t.at(j)) {
				count++;
			}
		}
	}


	
	//count = count / 2;
	cout << count << endl;	
}