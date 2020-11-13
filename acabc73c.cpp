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
    ll n,ans=0;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    for(auto x:mp){
        if(x.second%2==1){
            ans++;
        }
    }
    cout << ans << endl;
}
