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
    ll n;
    cin >> n;
    vector<ll> p(n),q(n),a(n);
    for (ll i = 0; i < n;i++){
        cin >> p[i];
        a[i] = p[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    sort(a.begin(), a.end());
    ll count = 0, countp = 0,countq=0;
    do
    {
        /*
        for (ll i=0;i<n;i++)
        {
            cout << a[i];
        }
        cout << endl;
        */
        count++;
        if (a ==p){
            countp = count;
        }
        if(a==q){
            countq = count;
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << abs(countq - countp) << endl;
    
}
