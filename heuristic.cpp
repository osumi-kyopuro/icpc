#include <iostream>
#include <vector>

using namespace std;
using ll=long long;
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)


// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

int main(){
    ll n,w,k,c,t;
    vector<pair<ll,ll>>water,house;
    cin>>n>>w>>k>>c;
    water.resize(w);
    house.resize(k);
    ll miny=n-1,minx=n-1,maxy=0,maxx=0;
    rep(i,0,w){
        ll a,b;
        cin>>a>>b;
        water[i]={a,b};
        chmin(miny,a);
        chmin(minx,b);
        chmax(maxy,a);
        chmax(maxx,b);
    }
    rep(i,0,k){
        ll c,d;
        cin>>c>>d;
        house[i]={c,d};
        chmin(miny,c);
        chmin(minx,d);
        chmax(maxy,c);
        chmax(maxx,d);
    }

    rep(i,miny,maxy+1){
        rep(j,minx,maxx+1){
            cout<<i<<" "<<j<<" "<<5000<<flush<<endl;
            cin>>t;
            if(t!=0){
              if(t==2){
                return 0;
              }
              if(t==-1){
                return -1;
              }
              break;
            }
        }
    }
    
}