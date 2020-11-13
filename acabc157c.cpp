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
/*階乗*/
ll factorial(ll n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
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
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>p;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        p.push_back(make_pair(a,b));
    }
    bool flag=true;
    string a;
    for(ll i=0;i<1000;i++){
        a=to_string(i);
        flag=true;
        for(ll j=0;j<m;j++){
            if(a[p[j].first-1]!=p[j].second+'0'){
                flag=false;
                break;
            }
            
        }
        if(flag&&a.size()==n){
            cout<<i<<endl;
            exit(0);
        }
        
    }
    cout<<-1<<endl;    
    
}