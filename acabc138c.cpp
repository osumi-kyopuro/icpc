#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main() {
	int n,t=0;
	cin >> n;
	vector<double>s(n,0);
	for (int i = 0; i < n; i++) {
		cin >> s[i];

	}
	sort(s.begin(), s.end());
	for (int i = 0; i<n;i++ ) {
		s[0]=(double) (s[0] + s[i]) / 2.0;
		//cout << s[i] << endl;
		//printf("%.1f", s[i]);
		/*for (int j = i + 1; j<n-1; j++) {
			s[j] = s[j + 1];
		}*/
	}
	printf("%.5f", s[0]);

}