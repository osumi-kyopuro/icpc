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
	ll n;
    cin>>n;
    vector<pair<ll,ll>>a(n);
    vector<ll>a2(n);
    for(ll i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;    
    }
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        a2[i]=a[i].first;
        //cout<<a2[i]<<endl;
    }
    for(ll i=0;i<n;i++){
        swap(a[i].first,a[i].second);
    }
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        if(a[i].second>=a2[n/2]){
            cout<<a2[n/2-1]<<endl;
        }
        else{
            cout<<a2[n/2]<<endl;
        }
    }







    
    

}