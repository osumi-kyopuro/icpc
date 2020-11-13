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

// 二項係数計算nCk
ll com(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
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
ll ismm(ll aa, ll p, ll m)
{
    ll ap = aa;
    ll ans = 1;
    while (p > 0)
    {
        //cout<<"p="<<p<<",ap="<<ap<<endl;
        if (p & 1)
        { //奇数が真
            ans = (ans * ap) % m;
        }
        p /= 2;
        ap = (ap * ap) % m;
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
    ll n;
    cin >> n;
    vector<ll>a(n);
    map<ll,ll>mx,my;
    rep(i, 0, n)
    {
        cin >> a[i];
        if (i % 2 == 0)
        {
            mx[a[i]]++;
        }
        else
        {
            my[a[i]]++;
        }
    }
    vector<P>px,py;
    for(auto x:mx){
        px.push_back({x.second,x.first});
    }
    for(auto y:my){
        py.push_back({y.second,y.first});
    }
    sort(all(px),greater<P>());
    sort(all(py),greater<P>());
    px.push_back({0,0});
    py.push_back({0,0});
    ll ans=a.size();
    if(px[0].second!=py[0].second){
        ans=min(ans,(ll)(a.size()-px[0].first-py[0].first));
    }
    if(px[0].second!=py[1].second){
        ans=min(ans,(ll)(a.size()-px[0].first-py[1].first));
    }
    if(px[1].second!=py[0].second){
        ans=min(ans,(ll)(a.size()-px[1].first-py[0].first));
    }


    cout<<ans<<endl;
}
