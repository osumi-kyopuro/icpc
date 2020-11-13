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
    ll n, m,ac=0,wa=0;
    cin>>n>>m;
    vector<bool> b(n+1,false);
    vector<ll> wav(n+1);
    
    for (ll i = 0; i < m;i++){
        ll p;
        string s;
        cin >> p >> s;
        if(!b[p]&&s=="WA"){
            wav[p]++;
        }
        else if(!b[p]&&s=="AC"){
            ac++;
            b[p] = true;
        }
    }
    for (ll i = 1; i <= n;i++){
        if(b[i]){
            wa += wav[i];
        }
    }
    cout << ac << " " << wa << endl;

}
