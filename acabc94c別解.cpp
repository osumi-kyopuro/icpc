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
    vector<ll>x(n),y(n);
    for(ll i=0;i<n;i++){
        cin>>x[i];
    }
    y=x;
    sort(y.begin(),y.end());
    for(ll i=0;i<n;i++){
        if(y[n/2]<=x[i]){
            cout<<y[n/2-1]<<endl;
        }
        else{
            cout<<y[n/2]<<endl;
        }
    }

    
    

}