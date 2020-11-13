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
/* ユークリッドの互除法 最大公約数*/
ll gcd(ll a, ll b)
{
    ll r;
    r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

/*最小公倍数*/
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

struct all_init
{
    all_init()
    {
        cout << fixed << setprecision(12);
    }
} All_init;

int main()
{
    ll n, x,sa1,g;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n;i++){
        cin >> a[i];
    }
    g = abs(a[0] - x);
    for (ll i = 0; i < n; i++)
    {
        sa1 = abs(a[i] - x);
        g = gcd(g, sa1);
    }
    cout << g << endl;
}