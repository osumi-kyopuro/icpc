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
    ll n,s;
    cin>>n;
    s=2025-n;
    for(ll i=1;i<=9;i++){
        for(ll j=1;j<=9;j++){
            if(i*j==s){
                cout<<i<<" x "<<j<<endl;
            }
        }
    }
}

