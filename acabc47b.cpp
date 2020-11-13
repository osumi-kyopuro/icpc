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
	ll w,h,n,sum=0,minx=0,miny=0;
	cin >> w>> h>> n;
	ll maxx = w, maxy = h;
	vector<ll>x(n),y(n),a(n);
	for (ll i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> a[i];
		if (a[i] == 1) {
			minx = max(x[i],minx);
		}
		else if (a[i] == 2) {
			maxx = min(x[i], maxx);
		}
		else if (a[i] == 3) {
			miny=max(y[i],miny);
		}
		else {
			maxy=min(y[i],maxy);
		}

	}
	if (maxx > minx&&maxy > miny) {
		cout << (maxx - minx)*(maxy - miny) << endl;
		//cout << minx <<" "<< maxx << " " << miny << " " << maxy << endl;
	}
	else {
		cout << '0' << endl;
	}


}

