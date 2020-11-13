#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
#define ll long long
using namespace std;

int main() {
	int n;
	int n1, n2, n3,n4,n5,n6;
	cin >> n;
	if (n / 3600 >= 1) {
		n1 =n/ 3600;
		n2 = n % 3600;
		printf("%02d:", n1);
	}
	else {
		printf("00:");
		n2 = n;
	}
	if (n2/ 60 >= 1) {
		n3 = n2 / 60;
		n4 = n2 % 60;
		printf("%02d:", n3);
	}
	else {
		printf("00:");
		n4 = n2;
	}
	printf("%02d\n", n4);
	

	
	
	
	
}