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
	ll R, G, B, n, count = 0;
	cin >> R >> G >> B >> n;
	for (ll i = 0; i <= 3000; i++) {
		for (ll j = 0; j <= 3000; j++) { 
			ll a = i * R + j * G;
			if (a<=n&&(n-a)%B==0) {
				//cout << i << " " << j << " " << (n - R*i - G*j)/B << endl;
				count++;
			}
		}
	}
	cout << count << endl; 
}
