#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <tuple>
#define ll long long
#define rep(i,s,n) for(ll i = (ll)(s); i < (ll)(n); i++)
#define all(a) (a).begin(),a.end()
#define mod 1000000007
using namespace std;
using graph =vector<vector<ll>>;
const ll MAX = 510000;
const ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void cominit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算nCk
ll com(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// 二項係数計算nPk
ll per(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[n-k] % MOD) % MOD;
}

// mod. m での a の逆元 a^{-1} を計算する
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

/* ユークリッドの互除法 最大公約数*/
ll gcd(ll a, ll b) {
	return b ? gcd(b,a%b) : a;
}



/*最小公倍数*/

ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}


/*二点間の距離*/
double dist(pair<double,double> a,pair<double,double> b){
	return sqrt(pow((a.first - b.first) ,2) + pow((a.second - b.second),2));
}

//繰り返し自乗法
double ism(double aa,ll p){
    double ap=aa;
    double ans=1;
    while(p>0){
        //cout<<"p="<<p<<",ap="<<ap<<endl;
        if(p&1){//奇数が真
            ans*=ap;
        }
        p/=2;
        ap=ap*ap;
    }
    return ans;

}
//繰り返し自乗法(アマリトリバージョン)
ll ismm(ll aa,ll p,ll m){
    ll ap=aa;
    ll ans=1;
    while(p>0){
        //cout<<"p="<<p<<",ap="<<ap<<endl;
        if(p&1){//奇数が真
            ans=(ans*ap)%m;    
        }
        p/=2;              
        ap=(ap*ap)%m;
    }
    return ans;

}
/*
ll solve(ll i,ll m,vector<ll>t,ll n){
    if(m==0){
        return 1;
    }
    if(i>=n){
        return 0;
    }
    
    
    cout<<i+1<<" "<<m<<endl;
    cout<<i+1<<" "<<m-t[i]<<endl;
    ll res=solve(i+1,m,t,n)||solve(i+1,m-t[i],t,n);
    return res;
}
*/


//小数点12桁
struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(12);
    }
} All_init;


int main()
{
    ll h,w;
    cin>>h>>w;
    vector<string>a(h);
    rep(i,0,h){
        cin>>a[i];        
    }
    vector<vector<ll>>dp(h,vector<ll>(w,0));
    dp[0][0]=1;
    rep(i,0,h){
        rep(j,0,w){
            if(i==0&&j==0){
                continue;
            }
            if(a[i][j]=='.'){
                if(i>0){
                    dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
                }
                if(j>0){
                    dp[i][j]=(dp[i][j-1]+dp[i][j])%mod;
                }
            }
        }
    }
    cout<<dp[h-1][w-1]<<endl;
    

    
    
}
