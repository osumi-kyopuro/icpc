#include <iostream>
#include <vector>
#define ll long long
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
using namespace std;

int main()
{
    ll n,w;
    cin>>n>>w;
    vector<ll>a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    bool exist=false;
    rep(bit,0,1<<n){    //例n=3の時　000から111までbit回す
        ll sum=0;   //総和初期化
        rep(i,0,n){        //(1<<i) i桁目のみが1、他は0であるビット列 
            if(bit&(1<<i)){//bitのi桁目が1であればi番目の数値足す
                sum+=a[i];
            }
        }
        if(sum==w){     //総和がｗになった場合はフラグを正
            exist=true;
        }
    }
    if(exist){          //フラグ正の場合
        cout<<"Yes"<<endl;
    }
    else{               //フラグ負の場合
        cout<<"No"<<endl;
    }
}
