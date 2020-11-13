#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	double w, h, x, y,k;
	cin >> w >> h >> x >> y;
	if (w/2==x&&h/2==y) {
		k = 1;
	}
	else {
		k = 0;
	}
	printf("%.9f %.0f", (h*w)/2, k);
}