#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#include<map>
#define ll long long
using namespace std;
ll keta(ll number) {
	ll d = 0;
	while (number != 0) {
		number = number / 10;
		d++;
	}
	return d;
}


int main() {
	ll a, b, big = 0, mae = 0, maei = 0, sx, k = 1;
	string x;
	cin >> a >> b >> x;
	sx = stoi(x);
	ll o = 10;
	for (ll i = sx; i >0; i--) {
		big = max(a*i + b * k, big);
		if (big <= sx) {
			mae = big;
			maei = i;
		}
		else {
			break;
		}
		if ((i + 1) % o == 0) {
			k++;
			o *= 10;

		}

	}
	cout << maei << endl;
	//cout << (sx - b * keta(i)) / a << endl;
}
