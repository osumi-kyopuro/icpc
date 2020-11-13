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
    ll n,sum=0;
    cin >> n;
    vector<ll>a(n+2,0),sa(n+1,0),sa2(n,0);
    for (ll i = 1; i < n+1;i++){
        cin >> a[i];
    }
    for (ll i = 0; i < n+1;i++){
        sum += abs(a[i + 1] - a[i]);
    }
    for (ll i = 0; i < n; i++)
    {
        ll sa = (abs(a[i + 1] - a[i]) + abs(a[i + 2] - a[i + 1])) - abs(a[i + 2] - a[i]);
        cout << sum - sa << endl;
    }
}