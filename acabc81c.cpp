#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>
#include<set>
#include<map>
#include<stack>
#define ll long long
using namespace std;
int main() {
    ll n,k,t,ans=0;
    cin>>n>>k;
    vector<pair<ll,ll>>p;
    vector<ll>count(200001,0);
    for(ll i=0;i<n;i++){
        cin>>t;
        count[t]++;
    }
    ll s=0;
    for(ll i=1;i<=200000;i++){
        if(count[i]){
            p.push_back(make_pair(count[i],i));
        }
    }
    sort(p.begin(),p.end());
    while(p.size()-s>k){
        ans+=p[s].first;
        s++;
    }
    cout<<ans<<endl;


}
 