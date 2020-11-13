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
#define ll long long
using namespace std;

int main()
{
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    ll left = 0, right = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n;i++){
        mp[a[i]]++;
    }
    for(auto p:mp){
        ll x = p.first;
        ll n = p.second;
        if(n<x){
            ans += n;
        }
        else{
            ans += n - x;
        }
    }
    cout << ans << endl;
}
