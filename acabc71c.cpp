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
    ll n,t=0,y=0;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end(),greater<ll>());
    bool flagb = true;
    bool flags = true;
    ll count = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        if(flagb&&a[i]==a[i+1]){
            t = a[i];
            flagb = false;
        }
        else if(flags&&count>=2&&a[i]==a[i+1]){
            y = a[i];
            flags = false;
            break;
        }
        if(!flagb)
        {
            count++;
        }
    }
    cout << y * t << endl;

}
