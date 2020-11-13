#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>
#include<set>
#include<map>
#include<stack>
#define ll long long
using namespace std;

int main() {
	ll n,count=0,sum=0;
	cin >> n;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(),a.end(),greater<ll>());
	for (ll i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	for (ll i = 0; i < n; i++) {
		if (suma + a[i] >= n) {   
			count++;
			cout << count << endl;
		}
		else {
			suma += a[i];
			count++;
		}
	}


}


