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
    ll n,m;
    cin>>n>>m;
    vector<tuple<ll, ll, string>> t;
    pair<ll, ll> p;
    for (ll i = 0; i < m; i++)
    {
        ll p;
        string s;
        cin >> p >> s;
        t.emplace_back(p, i, s);
    }
    ll a,wa=0;
    sort(t.begin(), t.end());
    bool flag = true;
    for (ll i = 0; i < m; i++)
    {
        /*
        cout <<get<0>(t[i])<<" ";
        cout << get<1>(t[i]) << " ";
        cout << get<2>(t[i]) <<endl;
        */
       if(a!=get<0>(t[i])){
           flag = true;
           wa = 0;
       }
       if(flag&&get<2>(t[i])=="AC"){
           flag = false;
           p.first++;
           p.second += wa;
       }
       else if(flag&&get<2>(t[i])=="WA"){
           wa++;
       }
       a = get<0>(t[i]);
    }
    cout << p.first << " " << p.second << endl;
}
