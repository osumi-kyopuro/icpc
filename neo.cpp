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
    ll n,sumsa1=0,ans;
    cin >> n;
    vector<ll> a(n+2),sa1(n+1,0),sa2(n,0);
    a[0] = 0;
    a[n + 1] = 0;
    for (ll i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n+1; i++)
    {    
        sa1[i] = abs(a[i] - a[i + 1]);
        sumsa1 += sa1[i];
    }
    for (ll i = 0; i < n; i++)
    {
        sa2[i] = abs(a[i] - a[i + 1]);
    }

    for (ll i = 0; i < n;i++){
        cout << sa2[i] + sumsa1 - (sa1[i] + sa1[i + 1]) << endl;
        
    }
    
}
