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
struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(12);
    }
} All_init;


int main()
{
    ll n,t;
    cin >> n;
    map<ll,ll>mp;
    for (ll i = 0; i < n;i++){;
        cin >> t;
        mp[t]=i+1;
    }
    vector<ll> ans;
    for (auto op : mp)
    {
        ans.emplace_back(op.second);
    }
    for (ll i = ans.size()-1; i >=0;i--){
        cout << ans[i] << endl;
    }
}
