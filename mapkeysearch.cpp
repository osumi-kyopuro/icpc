#include <iostream>
#include <map>
using namespace std;
int main()
{
	map<int, int> m1;

	m1[1] = 100;
	m1[2] = 200;
	m1[3] = 300;

	map<int, int> ::iterator it;
	it = m1.find(2);

	cout << it->first << " => " << it->second << endl;

	return 0;
}