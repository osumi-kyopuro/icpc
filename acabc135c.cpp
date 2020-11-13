#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<utility>
using namespace std;
int main() {
	long int n,sum=0;
	cin >> n;
	vector<long>a(n + 1);
	vector<long>b(n);
	for (int i = 0; i < n + 1; i++) {
		cin >> a.at(i);
	}
	for (int i = 0; i < n; i++) {
		cin >> b.at(i);

	}
	for (int i = 0; i < n; i++) {
		if (b.at(i) <= a.at(i)) {
			sum += b.at(i);
		}
		else if(b.at(i)<a.at(i)+a.at(i+1)) {
			sum += a.at(i);
			a.at(i+1) -= b.at(i) - a.at(i);
			sum += b.at(i) - a.at(i);
		}
		else {
			sum += a.at(i);
			sum += a.at(i + 1);
			a.at(i + 1) = 0;
		}
	}

	cout << sum << endl;

}