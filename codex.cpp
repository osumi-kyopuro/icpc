#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
using ll=long long;
using graph = vector<vector<ll>>;
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rrep(i, s, n) for (ll i = (ll)(s); i > (ll)(n); i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(),(a).rend()



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

//小数点12桁
struct all_init
{
    all_init()
    { 
        cout << fixed << setprecision(12);
    }
} All_init;

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



int main() {
    ll h,w,r,c;
    cin>>h>>w>>r>>c;
    vector<string>s(h);
    rep(i,0,h){
        cin>>s[i];
    }
    cout<<(s[r-1][c-1]=='#'?"Yes":"No")<<endl;


}