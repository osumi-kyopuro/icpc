#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define all(a) (a).begin(), a.end()
int main(){
    /*1があるか二分探索で求めるプログラム*/
    vector<int>card={5,3,2,1,4};
    sort(all(card));//昇順ソートする
    int ok=-1,ng=5;//区間を決める
    while(ng-ok>1){//区間が1になるまで
        int mid=(ok+ng)/2;//探索範囲の真ん中
        if(card[mid]>1){//1より大きい場合
            ng=mid;
        }
        else{//それ以外
            ok=mid;
        }
    }
    if(card[ok]==1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}