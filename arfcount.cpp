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
    vector<char> a(4);
    for (ll i = 0; i < 4;i++){
        cin >> a[i];
    }
    vector<ll> b(26, 0);
    for (ll i = 0; i < 4;i++){
        b[a[i]-'a']++;
    }
    for (ll i = 0; i < 26;i++){
        cout << b[i] << endl;
    }
}
