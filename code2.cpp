#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,a,n) for (int i = a; i < (n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
int mod = 998244353;
int INF = 1001001001;
using pll = pair<ll, ll>;

int main(){
    int R,C; cin>>R>>C;
    vector<vector<char>> S(R,vector<char> (C));
    rep(i,0,R) rep(j,0,C) cin>>S[i][j];

    vector<ll>p;//爆弾の威力
    vector<pair<ll,ll>>z;//爆弾の位置(y,x)
    rep(i,0,R){
        rep(j,0,C){
            if(S[i][j]>='1'&&S[i][j]<='9'){
                p.push_back((ll)(S[i][j]-'0'));
                z.push_back({i,j});
            }
        }
    }
    rep(i,0,z.size()){
        auto [zy,zx]=z[i];
        rep(a,0,R){
            rep(b,0,C){
                if((abs(zy-a)+abs(zx-b)<=p[i])) {
                    S[a][b]='.';
                }
            }
        }//るーぷおわ
    }
      //return 0;
    
    rep(i,0,R){
        rep(j,0,C){
            cout<<S[i][j];
        }
        cout<<endl;
    }
}
  