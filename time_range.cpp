#include <iostream>
using namespace std;


int main() {
    int start_time,end_time,target_time;
    cout<<"(時間範囲)開始時刻-->";
    cin>>start_time;
    cout<<"(時間範囲)終了時刻-->";
    cin>>end_time;
    cout<<"ある時刻-->";
    cin>>target_time;
    bool flag=false;
    if(start_time>end_time){//終了時刻より開始時刻の方が大きい場合
        if((start_time<=target_time && target_time<=end_time-1) 
        || ( 0<=target_time && target_time<=end_time-1)){
            flag=true;
        }
    }
    else if (start_time==end_time){//時間範囲が24時間の場合
        flag=true;
    }
    else{//開始時刻より終了時刻の方が大きい場合
        if (start_time<=target_time && target_time<=end_time-1){
            flag=true;
        }
    }
    if(flag){//指定した時間の範囲に含まれる場合
        cout<<"Yes"<<endl;
    }
    else{//指定した時間の範囲に含まれない場合
        cout<<"No"<<endl;
    }
    
}