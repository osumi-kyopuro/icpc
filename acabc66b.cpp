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
	string s;
	cin >> s;
	ll count = 0;
	for (ll i = s.size()-3; i >= 0; i-=2) {
		count = 0;
		for (ll j = 0; j <= i/2; j++) {
				if (s[j] == s[i/2+1+j]) {
					count++;
					if (count == i / 2 + 1) {
						cout << i + 1 << endl;
						exit(0);
					}
					
				}
				
			}

		}
	}

