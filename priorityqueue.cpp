#include<iostream>
#include<queue>
using namespace std;
int main() {
	priority_queue<int>que;
	// データを追加する
	que.push(3);
	que.push(1);
	que.push(4);

	// 処理順に出力する
	while (!que.empty()) {
		std::cout << que.top() << std::endl;
		que.pop();
	}
	system("pause");
}
