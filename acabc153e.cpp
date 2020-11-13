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
    ll h, n;
    cin >> h >> n;
    ll ans = LLONG_MAX;
    vector<ll> a(n), b(n), dp(h+10005, 1000000000);
    for (ll i = 0; i < n;i++){
        cin >> a[i] >> b[i];
    }
    dp[0] = 0;
    for (ll i = 1; i <h+10005; i++)
    {
        for (ll j = 0; j < n;j++){
            if(i-a[j]>=0){
                dp[i] = min(dp[i - a[j]] + b[j], dp[i]);
                if(i>=h&&dp[i]<1000000000){
                    ans = min(ans, dp[i]);
                    //cout << dp[i] << endl;
                }
            }
        }
    }
    cout << ans << endl;

}