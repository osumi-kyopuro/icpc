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
    ll n,T,sum=0;
    cin>>n>>T;
    vector<ll>t(n);
    cin>>t[0];
    for(ll i=1;i<n;i++){
        cin>>t[i];
        if(t[i]-t[i-1]<T){
            sum+=t[i]-t[i-1];
        }
        else{
            sum+=T;
            //cout<<"0"<<endl;
        }
    }
    sum+=T;
    cout<<sum<<endl;
}

