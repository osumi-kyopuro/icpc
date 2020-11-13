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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++)
    {
        ;
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end(), greater<pair<ll, ll>>());
    for (ll i = 0; i < n; i++)
    {
        cout << a[i].second << endl;
    }
}
