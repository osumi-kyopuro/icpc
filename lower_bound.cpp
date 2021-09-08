#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define all(a) (a).begin(), a.end()
int main() {
	/*1があるか二分探索で求めるプログラム*/
	vector<int>card={0,0,0,0,0};
	sort(all(card));
	//lower_bound:指定された要素以上の値が現れる最初の位置のイテレータを取得する。
	auto iter=lower_bound(all(card),1);
	int index=iter-card.begin();
	if(card[index]==1){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}