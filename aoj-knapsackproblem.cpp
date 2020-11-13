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
using namespace std;
using graph =vector<vector<ll>>;
/*階乗*/
ll factorial(ll n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1)%1000000007;
    }
}

/* ユークリッドの互除法 最大公約数*/
/*ll gcd(ll a, ll b) {
	ll r;
	r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
*/


/*最小公倍数*/
/*
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
*/

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
    ll n,w;
    cin>>n>>w;
    vector<ll>v(n,0),we(n,0);
    vector<vector<ll>>dp(n+1,vector<ll>(10001,0));
    for(ll i=0;i<n;i++){
        cin>>v[i]>>we[i];
    }
    for(ll j=0;j<w;j++){
        dp[0][j]=0;
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<=w;j++){
            if(j-we[i]>=0){
                dp[i+1][j]=max(dp[i][j-we[i]]+v[i],dp[i][j]);
            }
            else{
                dp[i+1][j]=dp[i][j];
            }
        }
    }
    cout<<dp[n][w]<<endl;



    
    
    
    
}