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
    ll n, m,ans;
    cin >> n >> m;
    if(n==1){
        if(m>=2){
            ans = m - 2;
        }
        else{
            ans = 1;
        }
    }
    else if (m == 1)
    {
        if (n >= 2)
        {
            ans = n - 2;
        }
        else
        {
            ans = 1;
        }
    }

    else{
        ans = (n - 2) * (m - 2);

    }
    cout << ans << endl;
}
