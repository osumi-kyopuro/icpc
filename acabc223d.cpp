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
#include <cctype>
#include <atcoder/all>
#include <random>
using namespace std;
typedef string::const_iterator State;
class ParseError {};
#define ll long long
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rrep(i, s, n) for (ll i = (ll)(s); i > (ll)(n); i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define mod 1000000007
#define P pair<ll, ll>
#define V vector<ll>
#define C vector<char>
#define B vector<bool>
#define endl '\n'
const ll MAX = 510000;
const ll MOD =1e+9+7;
using graph = vector<vector<ll>>;
int term(State &begin);
int number(State &begin);
int expression(State &begin);
int factor(State &begin);
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
		for (auto& x : Graph[v]) {
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




//小数点12桁
struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(30);
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
        for(auto& x:mp){//&はコンテナの値変更可能
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

// 負の数にも対応した % 演算
long long modxx(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

/*二点間の距離*/
double dist(pair<double, double> a, pair<double, double> b)
{
    return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

/*二点間の距離*/
long double dist2(pair<long double, long double> a, pair<long double, long double> b)
{
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

long double  kt(pair<long double, long double> a, pair<long double, long double> b){
    return abs((a.second-b.second)/(a.first-b.first));
}

/*
https://github.com/key-moon/Library/blob/master/src/Algorithm/rerooting.csx
keymoon による C# の実装を noshi91 が C++ に移植したものです
*/

#include <functional>
#include <stack>
#include <vector>

template <class T> class ReRooting {
public:
    int NodeCount;

private:
    std::vector<std::vector<int>> Adjacents;
    std::vector<std::vector<int>> IndexForAdjacent;

    std::vector<T> Res;
    std::vector<std::vector<T>> DP;

    T Identity;
    std::function<T(T, T)> Operate;
    std::function<T(T, int)> OperateNode;

public:
    ReRooting(int nodeCount, std::vector<std::vector<int>> edges, T identity,
                std::function<T(T, T)> operate,
                std::function<T(T, int)> operateNode) {
        NodeCount = nodeCount;

        Identity = identity;
        Operate = operate;
        OperateNode = operateNode;

        std::vector<std::vector<int>> adjacents(nodeCount);
        std::vector<std::vector<int>> indexForAdjacents(nodeCount);

        for (int i = 0; i < edges.size(); i++) {
            auto &edge = edges[i];
            indexForAdjacents[edge[0]].push_back(adjacents[edge[1]].size());
            indexForAdjacents[edge[1]].push_back(adjacents[edge[0]].size());
            adjacents[edge[0]].push_back(edge[1]);
            adjacents[edge[1]].push_back(edge[0]);
        }

        Adjacents = std::vector<std::vector<int>>(nodeCount);
        IndexForAdjacent = std::vector<std::vector<int>>(nodeCount);
        for (int i = 0; i < nodeCount; i++) {
            Adjacents[i] = adjacents[i];
            IndexForAdjacent[i] = indexForAdjacents[i];
        }

        DP = std::vector<std::vector<T>>(Adjacents.size());
        Res = std::vector<T>(Adjacents.size());

        for (int i = 0; i < Adjacents.size(); i++)
            DP[i] = std::vector<T>(Adjacents[i].size());
        if (NodeCount > 1)
            Initialize();
        else if (NodeCount == 1)
            Res[0] = OperateNode(Identity, 0);
    }

    T Query(int node) { return Res[node]; }

private:
    void Initialize() {
        std::vector<int> parents(NodeCount);
        std::vector<int> order(NodeCount);

#pragma region InitOrderedTree
        int index = 0;
        std::stack<int> stack;
        stack.push(0);
        parents[0] = -1;
        while (stack.size() > 0) {
            auto node = stack.top();
            stack.pop();
            order[index++] = node;
            for (int i = 0; i < Adjacents[node].size(); i++) {
                auto adjacent = Adjacents[node][i];
                if (adjacent == parents[node])
                    continue;
                stack.push(adjacent);
                parents[adjacent] = node;
            }
        }
#pragma endregion

#pragma region fromLeaf
        for (int i = order.size() - 1; i >= 1; i--) {
            auto node = order[i];
            auto parent = parents[node];

            T accum = Identity;
            int parentIndex = -1;
            for (int j = 0; j < Adjacents[node].size(); j++) {
                if (Adjacents[node][j] == parent) {
                    parentIndex = j;
                    continue;
                }
                accum = Operate(accum, DP[node][j]);
            }
            DP[parent][IndexForAdjacent[node][parentIndex]] =
                OperateNode(accum, node);
        }
#pragma endregion

#pragma region toLeaf
        for (int i = 0; i < order.size(); i++) {
            auto node = order[i];
            T accum = Identity;
            std::vector<T> accumsFromTail(Adjacents[node].size());
            accumsFromTail[accumsFromTail.size() - 1] = Identity;
            for (int j = accumsFromTail.size() - 1; j >= 1; j--)
                    accumsFromTail[j - 1] = Operate(DP[node][j], accumsFromTail[j]);
            for (int j = 0; j < accumsFromTail.size(); j++) {
                DP[Adjacents[node][j]][IndexForAdjacent[node][j]] =
                    OperateNode(Operate(accum, accumsFromTail[j]), node);
                accum = Operate(accum, DP[node][j]);
            }
            Res[node] = OperateNode(accum, node);
        }
#pragma endregion
    }
};


// グラフ、頂点の入次数、頂点数を受け取り、そのトポロジカルソートを記録した配列を返す関数
vector<ll> topological_sort(vector<vector<ll>> &G2, vector<ll> &indegree, ll V2) {
    // トポロジカルソートを記録する配列
    vector<ll> sorted_vertices;

    // 入次数が0の頂点を発見したら、処理待ち頂点としてキューに追加する
    queue<ll> que;
    for (ll i = 0; i < V2; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    // キューが空になるまで、操作1~3を繰り返す
    while (que.empty() == false) {
        // キューの先頭の頂点を取り出す
        ll v = que.front();
        que.pop();

        // その頂点と隣接している頂点の入次数を減らし、0になればキューに追加
        for (ll i = 0; i < G2[v].size(); i++) {
            ll u = G2[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) que.push(u);
        }
        // 頂点vを配列の末尾に追加する 
        sorted_vertices.push_back(v);
    }

    // トポロジカルソートを返す
    return sorted_vertices;
}



string long_to_string(long long N,long long k) {
	if (N == 0) {
		return "0";
	}
	string res;
	while (N > 0) {
		res = char(N % k + '0') + res;
		N /= k;
	}
	return res;
}

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(ll N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 1 は予めふるい落としておく
    isprime[1] = false;

    // ふるい
    for (ll p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (ll q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}


using namespace atcoder;

//using mint = modint1000000007;
//using namespace modint;
using mint = modint;


//弧度法の角度から度数法へ
double rad2deg(double rad){
    return rad * (180 / M_PI);
}




const long double EPS=1e-14;
#define PI 3.14159265359

void printArray2(string name,vector<V>& a){
    cout<<name<<endl;
    rep(i,0,a.size()){
        rep(j,0,a[i].size()){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void printArray(string name,vector<ll>& a){
    cout<<name<<endl;
    rep(i,0,a.size()){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}



int main() {
    ll n,m;
    cin>>n>>m;
    graph g(n);
    vector<ll>ind(n,0),ans;
    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        --a,--b;
        g[a].push_back(b);
    }
    rep(i,0,n){
        for(auto &x:g[i]){
            ind[x]++;
        }
    }
    //小さい順に取り出される優先度付きキュー
    priority_queue<ll,V,greater<ll>>pq;
    rep(i,0,n){
        if(ind[i]==0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        ll p=pq.top();
        pq.pop();
        ans.push_back(p+1);
        for(auto x:g[p]){
            ind[x]--;
            if(ind[x]==0){
                pq.push(x);
            }
        }
    }
    if(ans.size()!=n){
        cout<<-1<<endl;
    }
    else{
        rep(i,0,n){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    

}
