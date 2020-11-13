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
    ll n,ans=0; 
    cin>>n;
    vector<ll>a(n),count(n,0);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    while(a!=count){
        for(ll i=0;i<n;i++){
            if(a[i]!=count[i]){
                for(ll j=0;i+j<n;i++){
                    if(count[i+j]!=a[i]){
                        count[i+j]++;
                    }
                    else{
                        break;
                    }
                }
                /*for(ll i=0;i<n;i++){
                    cout<<count[i]<<endl;
                } */  

                ans++;
            }
        }

    }
    cout<<ans<<endl;

}
