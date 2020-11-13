#include <iostream>
#include <vector>
#include <string>
#define ll long long
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
using namespace std;

int main()
{
    string s;
    cin>>s;
    ll n=s.size();          //文字列の長さを取得
    bool flag=false;
    vector<bool> b(n-1);
    rep(bit,0,(1<<n-1)){    //---から+++を調べる
        ll sum=s[0]-'0';
        rep(j,0,n-1){
            if(bit&(1<<j)){ //j列目が+なら足す
                sum+=s[j+1]-'0';    //文字を数値に変換して足す
                b[j]=true;
            }
            else{           //j列目が-なら引く
                sum-=s[j+1]-'0';    //文字を数値に変換して引く
                b[j]=false;
            }
        }
        if(sum==7){
            rep(i,0,n){
                if(i!=n-1){
                    cout<<s[i]<<(b[i]?'+':'-');//b[i]が正なら+,b[i]が負なら-を表示
                }
                else{
                    cout<<s[i];
                }
            }
            cout<<"=7"<<endl;
            exit(0);         //強制終了
        }
    }
}