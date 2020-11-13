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
	ll a, b, c, x, y, ans;
	cin >> a >> b >> c >> x >> y;
	ans =LLONG_MAX;
	for (ll i = 0; i <= 200000; i++) {
		ans = min(ans,i * c + max(x - i/2,(ll)0)*a + max(y - i/2,(ll)0)*b);
	}
	cout << ans << endl;



}
