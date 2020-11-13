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

ll n;
vector<vector<P>> v;

// 整数 bit に対応する「決め打ち」が整合しているかを判定
bool judge(ll bit) {
    
    // i 人目の証言を検証する
    rep(i,0,n) {
        
        // i 人目が「不親切」だったら、証言はすべて無意味
        if ( !(bit & (1 << i)) ){ 
            continue;
        }


        // それぞれ確認
        for (P xy : v[i]) {
            ll x = xy.first; // x が
            ll y = xy.second; // y = 1: 正直、y = 0: 不親切

            // y = 1 なのに「不親切」だったらダメ
            if (y == 1 && !(bit & (1 << x))){ 
                return false;
            }

            // y = 0 なのに「正直者」だったらダメ
            if (y == 0 && (bit & (1 << x))){ 
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin>>n;
    v.resize(n);
    rep(i,0,n){
        ll a;
        cin>>a;
        v[i].resize(a);
        rep(j,0,a){
            cin>>v[i][j].first>>v[i][j].second;
            --v[i][j].first;
        }
    }

    ll res=0;
    rep(bit,0,(1<<n)){
        // 矛盾 check
        if (judge(bit)) {
            
            // bit に含まれる人数を数える
            ll count = 0;
            rep(i,0,n) {
                if (bit & (1 << i)){ 
                    count++;
                }
            }
            res = max(res, count);
        }
    }
    cout<<res<<endl;
    
}
