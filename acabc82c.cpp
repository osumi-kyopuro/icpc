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
    ll n,ans=0;
    cin >> n;
    vector<ll> a(n);
    ll left = 0,right = 0;
    for (ll i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while(right<n){
        if(a[right]==a[left]){
            
            right++;            
        }
        else{
            if(a[left]<=right-left){
                ans += right - left-a[left];
                //cout << "ans" << ans << endl;
                left = right;
            }
            else if(a[left]>right-left){
                ans += right-left;
                //cout << "ans" << ans << endl;
                left = right;
            }
        }
    }
    if(a[left]<=right-left){
        ans += right - left - a[left];
        //cout << "ans" << ans << endl;
    }
    else if (a[left] > right - left)
    {
        ans += right-left;
        //cout << "ans" << ans << endl;
    }

    cout << ans << endl;
}
