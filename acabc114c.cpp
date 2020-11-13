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
	ll n;
	cin >> n;
	string s = "";
	stack<string>st;
	vector<char>c = { '3','5','7' };
	st.push("3");
	st.push("5");
	st.push("7");
	int ans = 0;
	while (!st.empty()) {
		string a = st.top(); st.pop();
		//cout << a << endl;
		if (a.size() == 10) {
			continue;
		}

		ll check = stoll(a);
		bool anscheck = true;
		if (check > n) {
			anscheck = false;
		}
		for (ll j = 0; j < c.size(); j++) {
			bool flag = false;
			for (ll i = 0; i < a.size(); i++) {
				if (a[i] == c[j]) {
					flag = true;
				}
			}
			if (flag) {

			}
			else {
				anscheck = false;
			}
		}
		if (anscheck) {
			cout << a << endl;
			ans++;
		}

		for (ll i = 0; i < c.size(); i++) {
			st.push(a + c[i]);
		}



	}

	cout << ans << endl;

	//while (1);

}
