#include<iostream>
#include<queue>
using namespace std;
int main() {
	priority_queue<int>que;
	// �f�[�^��ǉ�����
	que.push(3);
	que.push(1);
	que.push(4);

	// �������ɏo�͂���
	while (!que.empty()) {
		std::cout << que.top() << std::endl;
		que.pop();
	}
	system("pause");
}
