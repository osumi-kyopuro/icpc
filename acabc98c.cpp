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
#include <limits>
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
    ll n;
    cin >> n;
    string s;
    cin>>s;
    ll e1=0, w1 = 0;
    vector<ll> e(n, 0);
    vector<ll> w(n, 0);
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == 'W')
        {
            w1++;
        }
        else if (s[i] == 'E')
        {
            e1++;
        }
        e[i] = e1;
        w[i] = w1;
    }
    ll ans = LLONG_MAX;
    for (ll i = 0; i < n; i++)
    {
        if(i==0){
            ans = min(e[n - 1] - e[i], ans);
        }
        else if(i==n-1){
            ans = min(ans, w[i - 1]);
        }
        else{
            ans = min(ans, w[i - 1] + e[n - 1] - e[i]);
        }
    }
    cout << ans << endl;
}