#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int x1, y1, x2, y2,x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	x3 = x2 - (y2 - y1);
	y3 = x2 - x1 + y2;
	x4 = x3 - (y3 - y2);
	y4 = x3 - x2 + y3;
	cout << x3 <<" "<< y3<< " " << x4<< " " << y4<<endl;

}