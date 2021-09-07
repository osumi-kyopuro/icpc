#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define all(a) (a).begin(), a.end()
int main() {
	/*1が何番目(0-indexed)にあるか二分探索で求めるプログラム*/
	vector<int>card={5,3,2,1,4};
	sort(all(card));
	//lower_bound:指定された要素以上の値が現れる最初の位置のイテレータを取得する。
	auto iter=lower_bound(all(card),1);
	int index=iter-card.begin();
	cout<<index<<endl;
}