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
#include <cstdio>
#define ll long long
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(a) (a).begin(), a.end()
#define mod 1000000007
#define P pair<ll, ll>
#define V vector<ll>
#define C vector<char>
#define B vector<bool>
#define endl '\n'
using namespace std;
using graph = vector<vector<ll>>;
const ll MAX = 510000;
const ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];


// テーブルを作る前処理
void cominit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// mod. m での a の逆元 a^{-1} を計算する
ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

// 二項係数計算nCk,n<=10^7,k<=10^7まで
ll com(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
//二項係数nCk,n<=10^9,k<=10^7まで
ll com2(ll n,ll k){
    ll res,bs=1,bb=1;
    for(ll i=0;i<k;i++){
        bs=(bs*(n-i))%mod;
        bb=(bb*(i+1))%mod;
    }
    res=modinv(bb,mod)%mod;
    res=(res*bs)%mod;
    return res;
}

// 二項係数計算nPk
ll per(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[n - k] % MOD) % MOD;
}


/* ユークリッドの互除法 最大公約数*/
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

/*最小公倍数*/

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

/*二点間の距離*/
double dist(pair<double, double> a, pair<double, double> b)
{
    return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

//繰り返し自乗法
double ism(double aa, ll p)
{
    double ap = aa;
    double ans = 1;
    while (p > 0)
    {
        //cout<<"p="<<p<<",ap="<<ap<<endl;
        if (p & 1)
        { //奇数が真
            ans *= ap;
        }
        p /= 2;
        ap = ap * ap;
    }
    return ans;
}
//繰り返し自乗法(アマリトリバージョン)
ll ismm(ll aa, ll p)
{
    ll ap = aa;
    ll ans = 1;
    while (p > 0)
    {
        //cout<<"p="<<p<<",ap="<<ap<<endl;
        if (p & 1)
        { //奇数が真
            ans = (ans * ap) % mod;
        }
        p /= 2;
        ap = (ap * ap) % mod;
    }
    return ans;
}



struct UnionFind
{
    vector<ll> par;

    UnionFind(ll n) : par(n, -1) {}

    ll root(ll x)
    {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(ll x, ll y)
    {
        return root(x) == root(y);
    }

    bool merge(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    ll size(ll x)
    {
        return -par[root(x)];
    }
};

using pint = pair<ll, ll>;
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
    ll h,w,ans=0;
    cin>>h>>w;
    vector<C>t(h+2,C(w+2));
    rep(i,1,h+1){
        rep(j,1,w+1){
            cin>>t[i][j];
        }
    }

    rep(sy,1,h+1){
        rep(sx,1,w+1){
            vector<V>d(h+2,V(w+2,-1));
            queue<P>que;
            que.push({sy,sx});
            d[sy][sx]=0;
            while(!que.empty()){
                P p=que.front();
                ll i=p.first,j=p.second;
                que.pop();
                if(t[i][j]=='.'){
                    if(t[i][j]==t[i+1][j]&&d[i+1][j]==-1){
                        d[i+1][j]=d[i][j]+1;
                        que.push({i+1,j});
                    }
                    if(t[i][j]==t[i][j+1]&&d[i][j+1]==-1){
                        d[i][j+1]=d[i][j]+1;
                        que.push({i,j+1});
                    }
                    if(t[i][j]==t[i][j-1]&&d[i][j-1]==-1){
                        d[i][j-1]=d[i][j]+1;
                        que.push({i,j-1});
                    }
                    if(t[i][j]==t[i-1][j]&&d[i-1][j]==-1){
                        d[i-1][j]=d[i][j]+1;
                        que.push({i-1,j});
                    }
                }
                if(d[i][j]!=-1){
                    ans=max(ans,d[i][j]);
                }
            }
        }
    }
    cout<<ans<<endl;
     
    
}
