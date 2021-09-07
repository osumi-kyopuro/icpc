#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define all(a) (a).begin(), a.end()
int main(){
    /*1が何番目(0-indexed)にあるか二分探索で求めるプログラム*/
    vector<int>card={5,3,2,1,4};
    sort(all(card));//昇順ソートする
    int ok=0,ng=5;//区間を決める
    while(ng-ok>1){//区間が1になるまで
        int mid=(ok+ng)/2;//探索範囲の真ん中
        if(card[mid]>3){//1より大きい場合
            ng=mid;
        }
        else{//1より小さい場合
            ok=mid;
        }
    }
    cout<<ok<<endl;
}