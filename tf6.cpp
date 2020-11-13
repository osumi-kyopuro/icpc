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
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <cstdint>
#include <cfenv>
#define ll long long
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rrep(i, s, n) for (ll i = (ll)(s); i > (ll)(n); i--)
#define all(a) (a).begin(), a.end()
#define rall(a) (a).rbegin(),(a).rend()
#define PI 3.14159265359
#define mod 1000000007
#define P pair<ll, ll>
#define V vector<ll>
#define C vector<char>
#define B vector<bool>
#define endl '\n'
const ll MAX = 510000;
const ll MOD = 1000000007;
using namespace std;
using graph = vector<vector<ll>>;
struct edge{
    //辺の重みを管理できるような構造体
	//コンストラクタによって簡単に値を入れられるようにしている
	//operatorは辺の重みでソート出来るようにしている
 
	ll from, to;
	ll cost;
	ll capa;
 
	edge(ll s, ll d) : from(s), to(d) { cost = 0; capa = 0; }
	edge(ll s, ll d, ll w) : from(s), to(d), cost(w) { capa = 0; }
	edge(ll s, ll d, ll x, ll y) :from(s), to(d), cost(x), capa(y) {}
 
	bool operator < (const edge& x) const {
		return cost < x.cost;
	}

};
using Graph=vector<vector<edge>>;//重み付きグラフ

//ダイクストラ法
vector<ll> Dijkstra(ll i, vector<vector<edge>> Graph) {
	//i:始点
	//Graph:重み付きグラフ
	ll n =Graph.size();
	vector<ll> d(n, LONG_MAX);
	d[i] = 0;
	priority_queue<
        pair<ll, ll>,//pair型 
        vector<pair<ll, ll>>,//内部コンテナ 
        greater<pair<ll, ll>>//昇順
        > q;
	q.push({0, i});//第一引数:コスト 第二引数:頂点
	while (!q.empty()) {
		pair<ll, ll> p = q.top();
		q.pop();
		int v = p.second;
		if (d[v] < p.first) {
			continue;
		}
		for (auto x : Graph[v]) {
			if (d[x.to] > d[v] + x.cost) {
				d[x.to] = d[v] + x.cost;
				q.push({d[x.to], x.to});
			}
		}
	}
	return d;
}

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

ll oddXOR(ll a) { return (a+1)/2 % 2; }
ll XOR(ll a) {
    if (a % 2 == 1) return oddXOR(a);
    else return oddXOR(a+1) ^ (a+1);
}

double median(V a){//中央値
    sort(all(a));
    if(a.size()%2==1){
        return a[(a.size()-1)/2];
    }
    else{
        return (a[(a.size()-1)/2]+a[(a.size()-1)/2+1])/2.0;
    }

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
            swap(x, y); // merge techniiue
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    ll size(ll x)
    {
        return -par[root(x)];
    }
};

//10の9乗+7でmodをとる
template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }

    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }


    constexpr modint &operator ++(auto) noexcept {
        ++a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator --(auto) noexcept {
        --a;
        if(a<0){
            a+=Modulus;
        }
        return *this;
    }

    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
        a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
};


//素因数分解の関数
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }
// 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

//約数列挙
vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i){
                 res.push_back(N/i);
                 
            } 

        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}


//桁数
ll Keta(ll x){
    ll cnt=1;
    while(x>=10){
        x/=10;
        cnt++;
    }
    return cnt;
}


//小数点12桁
struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(12);
    }
} All_init;



int main() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll q,x=0;
    cin>>q;
    vector<V>suma(26,V(100001,0));
    V a(26,0);
    rep(i,0,n){
        if(s[i]=='x'){
            x++;
        }
        a[s[i]-'a']++;
    }
    rep(i,0,26){
        suma[i][0]=a[i];
    }
    rep(i,0,26){
        rep(j,1,100001){
            if('x'-'a'==i){
                a[i]=(a[i]*x)%mod;
            }
            else{
                a[i]=(suma[i][0]+(a[i]*x)%mod)%mod;
            }
            suma[i][j]=a[i];
        }
    }
    V ans(q);
    rep(i,0,q){
        ll o;
        char c;
        cin>>o>>c;
        ans[i]=suma[c-'a'][o];
    }
    //cout<<suma[0][0]<<endl;
    rep(i,0,q){
        cout<<ans[i]<<endl;
    }


}
