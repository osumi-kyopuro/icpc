#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	string s;
	cin >> s;
	if (s == "Sunny") {
		cout << "Cloudy" << endl;
	}
	else if (s == "Cloudy") {
		cout << "Rainy" << endl;
	}
	else if (s == "Rainy") {
		cout << "Sunny" << endl;
	}

}