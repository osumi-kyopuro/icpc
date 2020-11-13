#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<climits>
#include<map>
#define ll long long
using namespace std;
int main() {
	ll k, s,count=0;
	cin >> k >> s;
	for (ll i = 0; i <=k ; i++) {
		for (ll j = 0; j <=k ; j++) {
			if (0<=s - (i + j)&&s-(i+j) <= k) {
				count++;
			}
		}
	}
	cout << count << endl;
}

