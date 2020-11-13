#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main()
{
    ll a, b, c, d;
	string s;
	cin >>s;
	a = s[0]-'0';//文字を数値に変換
	b = s[1]-'0';
	c = s[2]-'0';
	d = s[3]-'0';
 
	if (a + b + c + d == 7) {
		cout << a << "+" << b << "+" << c << "+" << d << "=" << 7 << endl;
	}
	else if (a + b + c - d == 7) {
		cout << a << "+" << b << "+" << c << "-" << d << "=" << 7 << endl;
	}
	else if (a + b - c + d == 7) {
		cout << a << "+" << b << "-" << c << "+" << d << "=" << 7 << endl;
	}
	else if (a + b - c - d == 7) {
		cout << a << "+" << b << "-" << c << "-" << d << "=" << 7 << endl;
	}
	else if (a - b + c + d == 7) {
		cout << a << "-" << b << "+" << c << "+" << d << "=" << 7 << endl;
	}
	else if (a - b - c + d == 7) {
		cout << a << "-" << b << "-" << c << "+" << d << "=" << 7 << endl;
	}
	else if (a - b + c - d == 7) {
		cout << a << "-" << b << "+" << c << "-" << d << "=" << 7 << endl;
	}
	else if (a - b - c - d == 7) {
		cout << a << "-" << b << "-" << c << "-" << d << "=" << 7 << endl;
	}
}