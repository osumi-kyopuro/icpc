#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<utility>
#include<stack>
using namespace std;
int main() {
	int a, b,x;
	string s;
	stack<int>S;
	while (cin >> s) {
		if (s[0] == '+') {
			a = S.top();
			S.pop();
			b = S.top();
			S.pop();
			S.push(a + b);

		}
		else if (s[0]=='-') {
			b = S.top();
			S.pop();
			a = S.top();
			S.pop();
			S.push(a - b);
		}
		else if (s[0] == '*') {
			a = S.top();
			S.pop();
			b = S.top();
			S.pop();
			S.push(a * b);
		}
		else {
			S.push(atoi(s.c_str()));
			cout << s[0] << endl;

		}
	}
	cout << S.top() << endl;
}