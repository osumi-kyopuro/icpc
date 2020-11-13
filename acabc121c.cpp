#include<iostream>
#include<string>
#include<vector> 
#include<algorithm>
#include<map>
using namespace std;


int main() {
	long long  m, n;
	long long sum = 0, sumen = 0;
	cin >> n >> m;
	vector<pair<long long, long long>>x(n);
	for (long long i = 0; i < n; i++) {
		cin >> x[i].first >> x[i].second;
	}
	sort(x.begin(), x.end());

	for (long long i = 0; i < n;i++) {
		if (sum + x[i].second >= m) {
			sumen += x[i].first*(m - sum);
			break;
		}
		else {
			sumen += x[i].first*x[i].second;
			sum += x[i].second;
		}
		
	}
	cout << sumen << endl;
}