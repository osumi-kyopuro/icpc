#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	for (int n = 0; n < 100; n++) {
		if (n % 5 == 0 && n % 3 == 0) {
			cout << "FizzBuzz" << endl;
		}
		else if (n % 3 == 0) {
			cout << "Fizz" << endl;
		}
		else if (n % 5 == 0) {
			cout << "Buzz" << endl;
		}
		else {
			cout << n << endl;
		}
	}

}
