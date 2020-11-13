#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
int main() {
	int q, x;
	string s;
	list<int>v;
	cin>>q;
	for (int i = 0; i < q; i++) {
		cin >> s;
		if (s == "insert") {
			cin>>x;
			v.push_front(x);
		}
		else if (s=="deletelast") {
			v.pop_back();
		}
		else if (s == "deletefirst") {
			v.pop_front();
		}
		else if(s=="delete") {
			cin>>x;
			for (list<int>::iterator it = v.begin(); it != v.end(); it++) {
				if (*it == x) {
					v.erase(it);
					break;
				}
			}
		}
	}
	for (list<int>::iterator it = v.begin(); it != v.end(); it++) {
		printf("%d", *it);
		printf(" ");
	}
	printf("\n");
}