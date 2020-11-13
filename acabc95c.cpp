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
	ll a, b, c, x, y,ans;
	cin >> a >> b >> c >> x >> y;
	ans= min({ a*x + b * y,
		2 * c*min(x,y) +( x>y?a:b)*(max(x,y) - min(x,y)),
		2*c*max(x,y)});
	//cout << 2 * c*min(x, y) << endl;
	//cout << (x > y ? a : b) << endl;
	//cout<< max(x, y) - min(x, y) << endl;
	//cout << (x > y ? a : b)*(max(x, y) - min(x, y)) << endl;
	//cout << 2 * c*min(x, y) + (x > y ? a : b)*(max(x, y) - min(x, y)) << endl;
	cout << ans << endl;

	
	
}
