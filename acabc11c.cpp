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
/*階乗*/
ll factorial(ll n){
    if(n==0){
        return 1;
    }
    else{
        return (n%mod)*(factorial(n-1)%mod);
    }
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
    ll n;
    cin>>n;
    vector<ll>g(3);
    rep(i,0,3){
        cin>>g[i];
    }
    rep(i,0,3){
        if(n==g[i]){
            cout<<"NO"<<endl;
            exit(0);
        }
    }
    sort(all(g));
    vector<ll>dp(n+1);
    dp[0]=0;
    ll k=0;
    rep(i,1,n+1){
        if(k<3&&i==g[k]){
            dp[i]=101;
            k++;
        }
        else{     
            if(i==1){
                dp[i]=dp[i-1]+1;
            }   
            else if(i==2){
                dp[i]=min(dp[i-1]+1,dp[i-2]+1);
            }
            else{
                dp[i]=min({dp[i-1]+1,dp[i-2]+1,dp[i-3]+1});
            }
        }
        
    }
    if(dp[n]<=100){
        cout<<"YES"<<endl;
        //cout<<dp[n]<<endl;
    }
    else{
        cout<<"NO"<<endl;
        //cout<<dp[n]<<endl;
    }
    

    
    
}
