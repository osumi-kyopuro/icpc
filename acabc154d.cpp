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
ll factorial(ll n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

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

struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(9);
    }
} All_init;


int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>p(n);
    vector<double>a(n,0);
    for(ll i=0;i<n;i++){
        cin>>p[i];
    }
    for(ll i=0;i<n;i++){
        a[i]=(p[i]+1)/2.0; //p[i]面あるサイコロの期待値
    }
    double q=0;
    double ans=0.0;
    vector<double>sum(n+1,0.0);
    for(ll i=1;i<=n;i++){
        //cout<<a[i]<<endl;
        q+=a[i-1];
        sum[i]=q;
        //cout<<sum[i]<<endl;
    }
    for(ll i=0;i<=n-k;i++){
        ans=max(ans,(double)(sum[i+k]-sum[i]));
    }
    cout<<ans<<endl;
    
}
