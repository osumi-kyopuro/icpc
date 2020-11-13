#include<iostream>
#include<queue>
using namespace std;
int main() {
	priority_queue<int>que;
	int n, m;
	long long sum = 0;
	cin >> n >> m;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		que.push(a[i]);
	}
	while (m > 0) {
		//cout << que.top() << endl;
		int t=que.top();
		que.pop();
		t /= 2;
		que.push(t);
		m--;
	}
	for (int i = 0; i < n; i++) {
		sum += que.top();
		que.pop();
	}
	cout << sum << endl;
	
	system("pause");
}
