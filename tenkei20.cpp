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
#include <list>
#include<string.h>
#include <iterator>
#include <bits/stdc++.h>
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
const ll MOD =1000000007;
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
vector<ll> Dijkstra(ll i, vector<vector<edge>> Graph,vector<V>T,vector<V>K) {
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
        fac[i] = fac[i - 1] * i% MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i)% MOD;
        finv[i] = finv[i - 1] * inv[i]% MOD;
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

//限界n<=1010,k<1010,modなし
#define CMAX 1010
int noinit = 1; ll memo[CMAX][CMAX];
ll aCb(ll a, ll b) {
    if (noinit) {
        rep(i, 0, CMAX) rep(j, 0, CMAX) memo[i][j] = -1;
        noinit = 0;
    }
    if (b == 0 || a == b) return 1;
    if (0 <= memo[a][b]) return memo[a][b];
    return memo[a][b] = aCb(a - 1, b - 1) + aCb(a - 1, b);
}

// 二項係数計算nCk,n<=10^7,k<=10^7まで
ll com(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k]% MOD) % MOD;
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
ll ismm(ll aa, ll p,ll m)
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
    ll forest;

    UnionFind(ll n) : par(n, -1) {forest=n;}

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
        if (x == y){
            return false;
        }
        if (par[x] > par[y]){
            swap(x, y); // merge technique
        }
        forest--;
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    ll size(ll x)
    {
        return -par[root(x)];
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

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

//多倍長整数対策
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}


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



//小数点12桁
struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(9);
    }
} All_init;

//Bit
// 1-indexedなので注意。
 struct BIT {
  private:
   vector<int> bit;
   int N;
 
  public:
   BIT(int size) {
     N = size;
     bit.resize(N + 1);
   }
 
   // 一点更新です
   void add(int a, int w) {
     for (int x = a; x <= N; x += x & -x) bit[x] += w;
   }
 
   // 1~Nまでの和を求める。
   int sum(int a) {
     int ret = 0;
     for (int x = a; x > 0; x -= x & -x) ret += bit[x];
     return ret;
   }
 };





/* SegTree<X>(n,fx): モノイド(集合X, 二項演算fx)についてサイズnで構築
    set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b):  [a,b) 全てにfxを作用させた値を取得。O(log(n))
*/
template <typename X>
struct SegTree {
    using FX = function<X(X, X)>;
    int n;
    FX fx;
    vector<X> dat;
    SegTree(int n_, FX fx_): n(), fx(fx_),dat(n_ * 4) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
 
    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }
 
    void update(int i, X x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
 
    // the minimum element of [a,b)
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    X query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return pow(2,31);
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    /* debug */

    inline X operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < n; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};


struct Zip{
    map<ll,ll>mp;
    Zip(vector<ll>a){
        rep(i,0,a.size()){
            mp[a[i]]=0;    
        }
        ll size=0;
        for(auto &x:mp){//&はコンテナの値変更可能
            x.second=size;
            size++;    
        }
    }
    ll zip(ll n){
        return mp[n];
    }
    ll size(){
        return mp.size();
    }
};


// 以下に、24時間表記の時計構造体 Clock を定義する
struct Clock{
    int hour;    //時間を表す (0~23の値をとる)
	int minute;  //分を表す   (0~59の値をとる)
	int second;  //秒を表す   (0~59の値をとる)

// メンバ関数 set の定義を書く
//   関数名: set
//   引数: int h, int m, int s (それぞれ時、分、秒を表す)
//   返り値: なし
//   関数の説明:
//     時・分・秒を表す3つの引数を受け取り、
//     それぞれ、メンバ変数 hour, minute, second に代入する
	void set(int h,int m,int s){
    	hour=h;
     	minute=m;
      	second=s;
    }
     
     
// メンバ関数 to_str の定義を書く
//   関数名: to_str
//   引数: なし
//   返り値: string型
//   関数の仕様:
//     メンバ変数が表す時刻の文字列を返す
//     時刻の文字列は次のフォーマット
//     "HH:MM:SS"
//     HH、MM、SSはそれぞれ時間、分、秒を2桁で表した文字列
	string to_str(){
    	string res;
    	if(hour<10){
        	res+="0";
        }
      	res+=to_string(hour);
      	res+=":";
      	if(minute<10){
        	res+="0";
        }
      	res+=to_string(minute);
      	res+=":";
      	if(second<10){
        	res+="0";
        }
      	res+=to_string(second);
      	return res;
    }

// メンバ関数 shift の定義を書く
//   関数名: shift
//   引数: int diff_second
//   返り値: なし
//   関数の仕様:
//     diff_second 秒だけメンバ変数が表す時刻を変更する(ただし、日付やうるう秒は考えない)
//     diff_second の値が負の場合、時刻を戻す
//     diff_second の値が正の場合、時刻を進める
//     diff_second の値は -86400 ~ 86400 の範囲を取とりうる
  	void shift(int diff_second){
    	int diff_hour=diff_second/3600;
      	diff_second%=3600;
      	int diff_minute=diff_second/60;
      	diff_second%=60;
      
      	second+=diff_second;
      	if(second>=60){
        	second-=60;
          	minute+=1;
        }
      	else if(second<0){
        	second+=60;
          	minute-=1;
        }
      
      	minute+=diff_minute;
      	if(minute>=60){
        	minute-=60;
          	hour+=1;
        }
      	else if(minute<0){
        	minute+=60;
          	hour-=1;
        }
      
      
      	hour+=diff_hour;
      	if(hour>=24){
        	hour-=24;
        }
      	else if(hour<0){
        	hour+=24;
        }    	
    	
    }
  
  
};


long long base8_to_long(string N) {
	long long res = 0;
	for (int i = 0; i < N.size(); ++i) {
		res = res * 8 + int(N[i] - '0');
	}
	return res;
}
string long_to_base9(long long N) {
	if (N == 0) {
		return "0";
	}
	string res;
	while (N > 0) {
		res = char(N % 9 + '0') + res;
		N /= 9;
	}
	return res;
}


int main() {
    ll a,b,c;
    cin>>a>>b>>c;
    ll d=1;
    rep(i,0,b){
        d*=c;
    }
    if(d>a){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
   

    
