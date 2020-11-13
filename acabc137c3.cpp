#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int main() {
	long long n, k = 0, count = 0;
	cin >> n;
	string s;
	//vector<string>t(n);
	map<string,long long>mp;
	//map<string, long long>::iterator it;
	for (long long i = 0; i < n; i++) {
		cin >> s;
		sort(s.begin(), s.end());
		cout << s << endl;
		cout << mp.size() << endl;
		mp[s]++;
		cout << mp[s] << endl;
		cout << mp.size() << endl;
	}
	
	for (auto& x:mp) {
		//cout << x.second << endl;
		count += x.second*(x.second-1)/2;
		//cout << count << endl;
		
	}

	//cout << count << endl;

	
}